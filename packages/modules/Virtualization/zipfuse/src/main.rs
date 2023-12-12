/*
 * Copyright (C) 2021 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

//! `zipfuse` is a FUSE filesystem for zip archives. It provides transparent access to the files
//! in a zip archive. This filesystem does not supporting writing files back to the zip archive.
//! The filesystem has to be mounted read only.

mod inode;

use anyhow::Result;
use clap::{App, Arg};
use fuse::filesystem::*;
use fuse::mount::*;
use std::collections::HashMap;
use std::convert::TryFrom;
use std::ffi::{CStr, CString};
use std::fs::{File, OpenOptions};
use std::io;
use std::io::Read;
use std::mem::size_of;
use std::os::unix::io::AsRawFd;
use std::path::Path;
use std::sync::Mutex;

use crate::inode::{DirectoryEntry, Inode, InodeData, InodeKind, InodeTable};

fn main() -> Result<()> {
    let matches = App::new("zipfuse")
        .arg(Arg::with_name("ZIPFILE").required(true))
        .arg(Arg::with_name("MOUNTPOINT").required(true))
        .get_matches();

    let zip_file = matches.value_of("ZIPFILE").unwrap().as_ref();
    let mount_point = matches.value_of("MOUNTPOINT").unwrap().as_ref();
    run_fuse(zip_file, mount_point)?;
    Ok(())
}

/// Runs a fuse filesystem by mounting `zip_file` on `mount_point`.
pub fn run_fuse(zip_file: &Path, mount_point: &Path) -> Result<()> {
    const MAX_READ: u32 = 1 << 20; // TODO(jiyong): tune this
    const MAX_WRITE: u32 = 1 << 13; // This is a read-only filesystem

    let dev_fuse = OpenOptions::new().read(true).write(true).open("/dev/fuse")?;

    fuse::mount(
        mount_point,
        "zipfuse",
        libc::MS_NOSUID | libc::MS_NODEV | libc::MS_RDONLY,
        &[
            MountOption::FD(dev_fuse.as_raw_fd()),
            MountOption::RootMode(libc::S_IFDIR | libc::S_IXUSR | libc::S_IXGRP | libc::S_IXOTH),
            MountOption::AllowOther,
            MountOption::UserId(0),
            MountOption::GroupId(0),
            MountOption::MaxRead(MAX_READ),
        ],
    )?;
    Ok(fuse::worker::start_message_loop(dev_fuse, MAX_READ, MAX_WRITE, ZipFuse::new(zip_file)?)?)
}

struct ZipFuse {
    zip_archive: Mutex<zip::ZipArchive<File>>,
    inode_table: InodeTable,
    open_files: Mutex<HashMap<Handle, OpenFileBuf>>,
    open_dirs: Mutex<HashMap<Handle, OpenDirBuf>>,
}

/// Holds the (decompressed) contents of a [`ZipFile`].
///
/// This buf is needed because `ZipFile` is in general not seekable due to the compression.
///
/// TODO(jiyong): do this only for compressed `ZipFile`s. Uncompressed (store) files don't need
/// this; they can be directly read from `zip_archive`.
struct OpenFileBuf {
    open_count: u32, // multiple opens share the buf because this is a read-only filesystem
    buf: Box<[u8]>,
}

/// Holds the directory entries in a directory opened by [`opendir`].
struct OpenDirBuf {
    open_count: u32,
    buf: Box<[(CString, DirectoryEntry)]>,
}

type Handle = u64;

fn ebadf() -> io::Error {
    io::Error::from_raw_os_error(libc::EBADF)
}

fn timeout_max() -> std::time::Duration {
    std::time::Duration::new(u64::MAX, 1_000_000_000 - 1)
}

impl ZipFuse {
    fn new(zip_file: &Path) -> Result<ZipFuse> {
        // TODO(jiyong): Use O_DIRECT to avoid double caching.
        // `.custom_flags(nix::fcntl::OFlag::O_DIRECT.bits())` currently doesn't work.
        let f = OpenOptions::new().read(true).open(zip_file)?;
        let mut z = zip::ZipArchive::new(f)?;
        let it = InodeTable::from_zip(&mut z)?;
        Ok(ZipFuse {
            zip_archive: Mutex::new(z),
            inode_table: it,
            open_files: Mutex::new(HashMap::new()),
            open_dirs: Mutex::new(HashMap::new()),
        })
    }

    fn find_inode(&self, inode: Inode) -> io::Result<&InodeData> {
        self.inode_table.get(inode).ok_or_else(ebadf)
    }

    // TODO(jiyong) remove this. Right now this is needed to do the nlink_t to u64 conversion below
    // on aosp_x86_64 target. That however is a useless conversion on other targets.
    #[allow(clippy::useless_conversion)]
    fn stat_from(&self, inode: Inode) -> io::Result<libc::stat64> {
        let inode_data = self.find_inode(inode)?;
        let mut st = unsafe { std::mem::MaybeUninit::<libc::stat64>::zeroed().assume_init() };
        st.st_dev = 0;
        st.st_nlink = if let Some(directory) = inode_data.get_directory() {
            (2 + directory.len() as libc::nlink_t).into()
        } else {
            1
        };
        st.st_ino = inode;
        st.st_mode = if inode_data.is_dir() { libc::S_IFDIR } else { libc::S_IFREG };
        st.st_mode |= inode_data.mode;
        st.st_uid = 0;
        st.st_gid = 0;
        st.st_size = i64::try_from(inode_data.size).unwrap_or(i64::MAX);
        Ok(st)
    }
}

impl fuse::filesystem::FileSystem for ZipFuse {
    type Inode = Inode;
    type Handle = Handle;
    type DirIter = DirIter;

    fn init(&self, _capable: FsOptions) -> std::io::Result<FsOptions> {
        // The default options added by the fuse crate are fine. We don't have additional options.
        Ok(FsOptions::empty())
    }

    fn lookup(&self, _ctx: Context, parent: Self::Inode, name: &CStr) -> io::Result<Entry> {
        let inode = self.find_inode(parent)?;
        let directory = inode.get_directory().ok_or_else(ebadf)?;
        let entry = directory.get(name);
        match entry {
            Some(e) => Ok(Entry {
                inode: e.inode,
                generation: 0,
                attr: self.stat_from(e.inode)?,
                attr_timeout: timeout_max(), // this is a read-only fs
                entry_timeout: timeout_max(),
            }),
            _ => Err(io::Error::from_raw_os_error(libc::ENOENT)),
        }
    }

    fn getattr(
        &self,
        _ctx: Context,
        inode: Self::Inode,
        _handle: Option<Self::Handle>,
    ) -> io::Result<(libc::stat64, std::time::Duration)> {
        let st = self.stat_from(inode)?;
        Ok((st, timeout_max()))
    }

    fn open(
        &self,
        _ctx: Context,
        inode: Self::Inode,
        _flags: u32,
    ) -> io::Result<(Option<Self::Handle>, fuse::filesystem::OpenOptions)> {
        let mut open_files = self.open_files.lock().unwrap();
        let handle = inode as Handle;

        // If the file is already opened, just increase the reference counter. If not, read the
        // entire file content to the buffer. When `read` is called, a portion of the buffer is
        // copied to the kernel.
        // TODO(jiyong): do this only for compressed zip files. Files that are not compressed
        // (store) can be directly read from zip_archive. That will help reduce the memory usage.
        if let Some(ofb) = open_files.get_mut(&handle) {
            if ofb.open_count == 0 {
                return Err(ebadf());
            }
            ofb.open_count += 1;
        } else {
            let inode_data = self.find_inode(inode)?;
            let zip_index = inode_data.get_zip_index().ok_or_else(ebadf)?;
            let mut zip_archive = self.zip_archive.lock().unwrap();
            let mut zip_file = zip_archive.by_index(zip_index)?;
            let mut buf = Vec::with_capacity(inode_data.size as usize);
            zip_file.read_to_end(&mut buf)?;
            open_files.insert(handle, OpenFileBuf { open_count: 1, buf: buf.into_boxed_slice() });
        }
        // Note: we don't return `DIRECT_IO` here, because then applications wouldn't be able to
        // mmap the files.
        Ok((Some(handle), fuse::filesystem::OpenOptions::empty()))
    }

    fn release(
        &self,
        _ctx: Context,
        inode: Self::Inode,
        _flags: u32,
        _handle: Self::Handle,
        _flush: bool,
        _flock_release: bool,
        _lock_owner: Option<u64>,
    ) -> io::Result<()> {
        // Releases the buffer for the `handle` when it is opened for nobody. While this is good
        // for saving memory, this has a performance implication because we need to decompress
        // again when the same file is opened in the future.
        let mut open_files = self.open_files.lock().unwrap();
        let handle = inode as Handle;
        if let Some(ofb) = open_files.get_mut(&handle) {
            if ofb.open_count.checked_sub(1).ok_or_else(ebadf)? == 0 {
                open_files.remove(&handle);
            }
            Ok(())
        } else {
            Err(ebadf())
        }
    }

    fn read<W: io::Write + ZeroCopyWriter>(
        &self,
        _ctx: Context,
        _inode: Self::Inode,
        handle: Self::Handle,
        mut w: W,
        size: u32,
        offset: u64,
        _lock_owner: Option<u64>,
        _flags: u32,
    ) -> io::Result<usize> {
        let open_files = self.open_files.lock().unwrap();
        let ofb = open_files.get(&handle).ok_or_else(ebadf)?;
        if ofb.open_count == 0 {
            return Err(ebadf());
        }
        let start = offset as usize;
        let end = start + size as usize;
        let end = std::cmp::min(end, ofb.buf.len());
        let read_len = w.write(&ofb.buf[start..end])?;
        Ok(read_len)
    }

    fn opendir(
        &self,
        _ctx: Context,
        inode: Self::Inode,
        _flags: u32,
    ) -> io::Result<(Option<Self::Handle>, fuse::filesystem::OpenOptions)> {
        let mut open_dirs = self.open_dirs.lock().unwrap();
        let handle = inode as Handle;
        if let Some(odb) = open_dirs.get_mut(&handle) {
            if odb.open_count == 0 {
                return Err(ebadf());
            }
            odb.open_count += 1;
        } else {
            let inode_data = self.find_inode(inode)?;
            let directory = inode_data.get_directory().ok_or_else(ebadf)?;
            let mut buf: Vec<(CString, DirectoryEntry)> = Vec::with_capacity(directory.len());
            for (name, dir_entry) in directory.iter() {
                let name = CString::new(name.as_bytes()).unwrap();
                buf.push((name, dir_entry.clone()));
            }
            open_dirs.insert(handle, OpenDirBuf { open_count: 1, buf: buf.into_boxed_slice() });
        }
        Ok((Some(handle), fuse::filesystem::OpenOptions::CACHE_DIR))
    }

    fn releasedir(
        &self,
        _ctx: Context,
        inode: Self::Inode,
        _flags: u32,
        _handle: Self::Handle,
    ) -> io::Result<()> {
        let mut open_dirs = self.open_dirs.lock().unwrap();
        let handle = inode as Handle;
        if let Some(odb) = open_dirs.get_mut(&handle) {
            if odb.open_count.checked_sub(1).ok_or_else(ebadf)? == 0 {
                open_dirs.remove(&handle);
            }
            Ok(())
        } else {
            Err(ebadf())
        }
    }

    fn readdir(
        &self,
        _ctx: Context,
        inode: Self::Inode,
        _handle: Self::Handle,
        size: u32,
        offset: u64,
    ) -> io::Result<Self::DirIter> {
        let open_dirs = self.open_dirs.lock().unwrap();
        let handle = inode as Handle;
        let odb = open_dirs.get(&handle).ok_or_else(ebadf)?;
        if odb.open_count == 0 {
            return Err(ebadf());
        }
        let buf = &odb.buf;
        let start = offset as usize;

        // Estimate the size of each entry will take space in the buffer. See
        // external/crosvm/fuse/src/server.rs#add_dirent
        let mut estimate: usize = 0; // estimated number of bytes we will be writing
        let mut end = start; // index in `buf`
        while estimate < size as usize && end < buf.len() {
            let dirent_size = size_of::<fuse::sys::Dirent>();
            let name_size = buf[end].0.to_bytes().len();
            estimate += (dirent_size + name_size + 7) & !7; // round to 8 byte boundary
            end += 1;
        }

        let mut new_buf = Vec::with_capacity(end - start);
        // The portion of `buf` is *copied* to the iterator. This is not ideal, but inevitable
        // because the `name` field in `fuse::filesystem::DirEntry` is `&CStr` not `CString`.
        new_buf.extend_from_slice(&buf[start..end]);
        Ok(DirIter { inner: new_buf, offset, cur: 0 })
    }
}

struct DirIter {
    inner: Vec<(CString, DirectoryEntry)>,
    offset: u64, // the offset where this iterator begins. `next` doesn't change this.
    cur: usize,  // the current index in `inner`. `next` advances this.
}

impl fuse::filesystem::DirectoryIterator for DirIter {
    fn next(&mut self) -> Option<fuse::filesystem::DirEntry> {
        if self.cur >= self.inner.len() {
            return None;
        }

        let (name, entry) = &self.inner[self.cur];
        self.cur += 1;
        Some(fuse::filesystem::DirEntry {
            ino: entry.inode as libc::ino64_t,
            offset: self.offset + self.cur as u64,
            type_: match entry.kind {
                InodeKind::Directory => libc::DT_DIR.into(),
                InodeKind::File => libc::DT_REG.into(),
            },
            name,
        })
    }
}

#[cfg(test)]
mod tests {
    use anyhow::{bail, Result};
    use nix::sys::statfs::{statfs, FsType};
    use std::collections::BTreeSet;
    use std::fs;
    use std::fs::File;
    use std::io::Write;
    use std::path::{Path, PathBuf};
    use std::time::{Duration, Instant};
    use zip::write::FileOptions;

    #[cfg(not(target_os = "android"))]
    fn start_fuse(zip_path: &Path, mnt_path: &Path) {
        let zip_path = PathBuf::from(zip_path);
        let mnt_path = PathBuf::from(mnt_path);
        std::thread::spawn(move || {
            crate::run_fuse(&zip_path, &mnt_path).unwrap();
        });
    }

    #[cfg(target_os = "android")]
    fn start_fuse(zip_path: &Path, mnt_path: &Path) {
        // Note: for some unknown reason, running a thread to serve fuse doesn't work on Android.
        // Explicitly spawn a zipfuse process instead.
        // TODO(jiyong): fix this
        assert!(std::process::Command::new("sh")
            .arg("-c")
            .arg(format!("/data/local/tmp/zipfuse {} {}", zip_path.display(), mnt_path.display()))
            .spawn()
            .is_ok());
    }

    fn wait_for_mount(mount_path: &Path) -> Result<()> {
        let start_time = Instant::now();
        const POLL_INTERVAL: Duration = Duration::from_millis(50);
        const TIMEOUT: Duration = Duration::from_secs(10);
        const FUSE_SUPER_MAGIC: FsType = FsType(0x65735546);
        loop {
            if statfs(mount_path)?.filesystem_type() == FUSE_SUPER_MAGIC {
                break;
            }

            if start_time.elapsed() > TIMEOUT {
                bail!("Time out mounting zipfuse");
            }
            std::thread::sleep(POLL_INTERVAL);
        }
        Ok(())
    }

    // Creates a zip file, adds some files to the zip file, mounts it using zipfuse, runs the check
    // routine, and finally unmounts.
    fn run_test(add: fn(&mut zip::ZipWriter<File>), check: fn(&std::path::Path)) {
        // Create an empty zip file
        let test_dir = tempfile::TempDir::new().unwrap();
        let zip_path = test_dir.path().join("test.zip");
        let zip = File::create(&zip_path);
        assert!(zip.is_ok());
        let mut zip = zip::ZipWriter::new(zip.unwrap());

        // Let test users add files/dirs to the zip file
        add(&mut zip);
        assert!(zip.finish().is_ok());
        drop(zip);

        // Mount the zip file on the "mnt" dir using zipfuse.
        let mnt_path = test_dir.path().join("mnt");
        assert!(fs::create_dir(&mnt_path).is_ok());

        start_fuse(&zip_path, &mnt_path);

        let mnt_path = test_dir.path().join("mnt");
        // Give some time for the fuse to boot up
        assert!(wait_for_mount(&mnt_path).is_ok());
        // Run the check routine, and do the clean up.
        check(&mnt_path);
        assert!(nix::mount::umount2(&mnt_path, nix::mount::MntFlags::empty()).is_ok());
    }

    fn check_file(root: &Path, file: &str, content: &[u8]) {
        let path = root.join(file);
        assert!(path.exists());

        let metadata = fs::metadata(&path);
        assert!(metadata.is_ok());

        let metadata = metadata.unwrap();
        assert!(metadata.is_file());
        assert_eq!(content.len(), metadata.len() as usize);

        let read_data = fs::read(&path);
        assert!(read_data.is_ok());
        assert_eq!(content, read_data.unwrap().as_slice());
    }

    fn check_dir<S: AsRef<str>>(root: &Path, dir: &str, files: &[S], dirs: &[S]) {
        let dir_path = root.join(dir);
        assert!(dir_path.exists());

        let metadata = fs::metadata(&dir_path);
        assert!(metadata.is_ok());

        let metadata = metadata.unwrap();
        assert!(metadata.is_dir());

        let iter = fs::read_dir(&dir_path);
        assert!(iter.is_ok());

        let iter = iter.unwrap();
        let mut actual_files = BTreeSet::new();
        let mut actual_dirs = BTreeSet::new();
        for de in iter {
            let entry = de.unwrap();
            let path = entry.path();
            if path.is_dir() {
                actual_dirs.insert(path.strip_prefix(&dir_path).unwrap().to_path_buf());
            } else {
                actual_files.insert(path.strip_prefix(&dir_path).unwrap().to_path_buf());
            }
        }
        let expected_files: BTreeSet<PathBuf> =
            files.iter().map(|s| PathBuf::from(s.as_ref())).collect();
        let expected_dirs: BTreeSet<PathBuf> =
            dirs.iter().map(|s| PathBuf::from(s.as_ref())).collect();

        assert_eq!(expected_files, actual_files);
        assert_eq!(expected_dirs, actual_dirs);
    }

    #[test]
    fn empty() {
        run_test(
            |_| {},
            |root| {
                check_dir::<String>(root, "", &[], &[]);
            },
        );
    }

    #[test]
    fn single_file() {
        run_test(
            |zip| {
                zip.start_file("foo", FileOptions::default()).unwrap();
                zip.write_all(b"0123456789").unwrap();
            },
            |root| {
                check_dir(root, "", &["foo"], &[]);
                check_file(root, "foo", b"0123456789");
            },
        );
    }

    #[test]
    fn single_dir() {
        run_test(
            |zip| {
                zip.add_directory("dir", FileOptions::default()).unwrap();
            },
            |root| {
                check_dir(root, "", &[], &["dir"]);
                check_dir::<String>(root, "dir", &[], &[]);
            },
        );
    }

    #[test]
    fn complex_hierarchy() {
        // root/
        //   a/
        //    b1/
        //    b2/
        //      c1 (file)
        //      c2/
        //          d1 (file)
        //          d2 (file)
        //          d3 (file)
        //  x/
        //    y1 (file)
        //    y2 (file)
        //    y3/
        //
        //  foo (file)
        //  bar (file)
        run_test(
            |zip| {
                let opt = FileOptions::default();
                zip.add_directory("a/b1", opt).unwrap();

                zip.start_file("a/b2/c1", opt).unwrap();

                zip.start_file("a/b2/c2/d1", opt).unwrap();
                zip.start_file("a/b2/c2/d2", opt).unwrap();
                zip.start_file("a/b2/c2/d3", opt).unwrap();

                zip.start_file("x/y1", opt).unwrap();
                zip.start_file("x/y2", opt).unwrap();
                zip.add_directory("x/y3", opt).unwrap();

                zip.start_file("foo", opt).unwrap();
                zip.start_file("bar", opt).unwrap();
            },
            |root| {
                check_dir(root, "", &["foo", "bar"], &["a", "x"]);
                check_dir(root, "a", &[], &["b1", "b2"]);
                check_dir::<String>(root, "a/b1", &[], &[]);
                check_dir(root, "a/b2", &["c1"], &["c2"]);
                check_dir(root, "a/b2/c2", &["d1", "d2", "d3"], &[]);
                check_dir(root, "x", &["y1", "y2"], &["y3"]);
                check_dir::<String>(root, "x/y3", &[], &[]);
                check_file(root, "a/b2/c1", &[]);
                check_file(root, "a/b2/c2/d1", &[]);
                check_file(root, "a/b2/c2/d2", &[]);
                check_file(root, "a/b2/c2/d3", &[]);
                check_file(root, "x/y1", &[]);
                check_file(root, "x/y2", &[]);
                check_file(root, "foo", &[]);
                check_file(root, "bar", &[]);
            },
        );
    }

    #[test]
    fn large_file() {
        run_test(
            |zip| {
                let data = vec![10; 2 << 20];
                zip.start_file("foo", FileOptions::default()).unwrap();
                zip.write_all(&data).unwrap();
            },
            |root| {
                let data = vec![10; 2 << 20];
                check_file(root, "foo", &data);
            },
        );
    }

    #[test]
    fn large_dir() {
        const NUM_FILES: usize = 1 << 10;
        run_test(
            |zip| {
                let opt = FileOptions::default();
                // create 1K files. Each file has a name of length 100. So total size is at least
                // 100KB, which is bigger than the readdir buffer size of 4K.
                for i in 0..NUM_FILES {
                    zip.start_file(format!("dir/{:0100}", i), opt).unwrap();
                }
            },
            |root| {
                let dirs_expected: Vec<_> = (0..NUM_FILES).map(|i| format!("{:0100}", i)).collect();
                check_dir(
                    root,
                    "dir",
                    dirs_expected.iter().map(|s| s.as_str()).collect::<Vec<&str>>().as_slice(),
                    &[],
                );
            },
        );
    }
}
