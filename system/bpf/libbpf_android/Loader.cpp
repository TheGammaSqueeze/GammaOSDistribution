/*
 * Copyright (C) 2018 The Android Open Source Project
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

#define LOG_TAG "LibBpfLoader"

#include <errno.h>
#include <linux/bpf.h>
#include <linux/elf.h>
#include <log/log.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/utsname.h>
#include <unistd.h>

// This is BpfLoader v0.2
#define BPFLOADER_VERSION_MAJOR 0u
#define BPFLOADER_VERSION_MINOR 2u
#define BPFLOADER_VERSION ((BPFLOADER_VERSION_MAJOR << 16) | BPFLOADER_VERSION_MINOR)

#include "../progs/include/bpf_map_def.h"
#include "bpf/BpfUtils.h"
#include "include/libbpf_android.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <optional>
#include <string>
#include <vector>

#include <android-base/strings.h>
#include <android-base/unique_fd.h>

#define BPF_FS_PATH "/sys/fs/bpf/"

// Size of the BPF log buffer for verifier logging
#define BPF_LOAD_LOG_SZ 0x1ffff

using android::base::StartsWith;
using android::base::unique_fd;
using std::ifstream;
using std::ios;
using std::optional;
using std::string;
using std::vector;

namespace android {
namespace bpf {

static string pathToFilename(const string& path, bool noext = false) {
    vector<string> spath = android::base::Split(path, "/");
    string ret = spath.back();

    if (noext) {
        size_t lastindex = ret.find_last_of('.');
        return ret.substr(0, lastindex);
    }
    return ret;
}

typedef struct {
    const char* name;
    enum bpf_prog_type type;
} sectionType;

/*
 * Map section name prefixes to program types, the section name will be:
 * SEC(<prefix>/<name-of-program>)
 * For example:
 * SEC("tracepoint/sched_switch_func") where sched_switch_funcs
 * is the name of the program, and tracepoint is the type.
 */
sectionType sectionNameTypes[] = {
        {"kprobe", BPF_PROG_TYPE_KPROBE},
        {"tracepoint", BPF_PROG_TYPE_TRACEPOINT},
        {"skfilter", BPF_PROG_TYPE_SOCKET_FILTER},
        {"cgroupskb", BPF_PROG_TYPE_CGROUP_SKB},
        {"schedcls", BPF_PROG_TYPE_SCHED_CLS},
        {"cgroupsock", BPF_PROG_TYPE_CGROUP_SOCK},
        {"xdp", BPF_PROG_TYPE_XDP},

        /* End of table */
        {"END", BPF_PROG_TYPE_UNSPEC},
};

typedef struct {
    enum bpf_prog_type type;
    string name;
    vector<char> data;
    vector<char> rel_data;
    optional<struct bpf_prog_def> prog_def;

    unique_fd prog_fd; /* fd after loading */
} codeSection;

static int readElfHeader(ifstream& elfFile, Elf64_Ehdr* eh) {
    elfFile.seekg(0);
    if (elfFile.fail()) return -1;

    if (!elfFile.read((char*)eh, sizeof(*eh))) return -1;

    return 0;
}

/* Reads all section header tables into an Shdr array */
static int readSectionHeadersAll(ifstream& elfFile, vector<Elf64_Shdr>& shTable) {
    Elf64_Ehdr eh;
    int ret = 0;

    ret = readElfHeader(elfFile, &eh);
    if (ret) return ret;

    elfFile.seekg(eh.e_shoff);
    if (elfFile.fail()) return -1;

    /* Read shdr table entries */
    shTable.resize(eh.e_shnum);

    if (!elfFile.read((char*)shTable.data(), (eh.e_shnum * eh.e_shentsize))) return -ENOMEM;

    return 0;
}

/* Read a section by its index - for ex to get sec hdr strtab blob */
static int readSectionByIdx(ifstream& elfFile, int id, vector<char>& sec) {
    vector<Elf64_Shdr> shTable;
    int ret = readSectionHeadersAll(elfFile, shTable);
    if (ret) return ret;

    elfFile.seekg(shTable[id].sh_offset);
    if (elfFile.fail()) return -1;

    sec.resize(shTable[id].sh_size);
    if (!elfFile.read(sec.data(), shTable[id].sh_size)) return -1;

    return 0;
}

/* Read whole section header string table */
static int readSectionHeaderStrtab(ifstream& elfFile, vector<char>& strtab) {
    Elf64_Ehdr eh;
    int ret = readElfHeader(elfFile, &eh);
    if (ret) return ret;

    ret = readSectionByIdx(elfFile, eh.e_shstrndx, strtab);
    if (ret) return ret;

    return 0;
}

/* Get name from offset in strtab */
static int getSymName(ifstream& elfFile, int nameOff, string& name) {
    int ret;
    vector<char> secStrTab;

    ret = readSectionHeaderStrtab(elfFile, secStrTab);
    if (ret) return ret;

    if (nameOff >= (int)secStrTab.size()) return -1;

    name = string((char*)secStrTab.data() + nameOff);
    return 0;
}

/* Reads a full section by name - example to get the GPL license */
static int readSectionByName(const char* name, ifstream& elfFile, vector<char>& data) {
    vector<char> secStrTab;
    vector<Elf64_Shdr> shTable;
    int ret;

    ret = readSectionHeadersAll(elfFile, shTable);
    if (ret) return ret;

    ret = readSectionHeaderStrtab(elfFile, secStrTab);
    if (ret) return ret;

    for (int i = 0; i < (int)shTable.size(); i++) {
        char* secname = secStrTab.data() + shTable[i].sh_name;
        if (!secname) continue;

        if (!strcmp(secname, name)) {
            vector<char> dataTmp;
            dataTmp.resize(shTable[i].sh_size);

            elfFile.seekg(shTable[i].sh_offset);
            if (elfFile.fail()) return -1;

            if (!elfFile.read((char*)dataTmp.data(), shTable[i].sh_size)) return -1;

            data = dataTmp;
            return 0;
        }
    }
    return -2;
}

unsigned int readSectionUint(const char* name, ifstream& elfFile, unsigned int defVal) {
    vector<char> theBytes;
    int ret = readSectionByName(name, elfFile, theBytes);
    if (ret) {
        ALOGD("Couldn't find section %s (defaulting to %u [0x%x]).\n", name, defVal, defVal);
        return defVal;
    } else if (theBytes.size() < sizeof(unsigned int)) {
        ALOGE("Section %s too short (defaulting to %u [0x%x]).\n", name, defVal, defVal);
        return defVal;
    } else {
        // decode first 4 bytes as LE32 uint, there will likely be more bytes due to alignment.
        unsigned int value = static_cast<unsigned char>(theBytes[3]);
        value <<= 8;
        value += static_cast<unsigned char>(theBytes[2]);
        value <<= 8;
        value += static_cast<unsigned char>(theBytes[1]);
        value <<= 8;
        value += static_cast<unsigned char>(theBytes[0]);
        ALOGI("Section %s value is %u [0x%x]\n", name, value, value);
        return value;
    }
}

static int readSectionByType(ifstream& elfFile, int type, vector<char>& data) {
    int ret;
    vector<Elf64_Shdr> shTable;

    ret = readSectionHeadersAll(elfFile, shTable);
    if (ret) return ret;

    for (int i = 0; i < (int)shTable.size(); i++) {
        if ((int)shTable[i].sh_type != type) continue;

        vector<char> dataTmp;
        dataTmp.resize(shTable[i].sh_size);

        elfFile.seekg(shTable[i].sh_offset);
        if (elfFile.fail()) return -1;

        if (!elfFile.read((char*)dataTmp.data(), shTable[i].sh_size)) return -1;

        data = dataTmp;
        return 0;
    }
    return -2;
}

static bool symCompare(Elf64_Sym a, Elf64_Sym b) {
    return (a.st_value < b.st_value);
}

static int readSymTab(ifstream& elfFile, int sort, vector<Elf64_Sym>& data) {
    int ret, numElems;
    Elf64_Sym* buf;
    vector<char> secData;

    ret = readSectionByType(elfFile, SHT_SYMTAB, secData);
    if (ret) return ret;

    buf = (Elf64_Sym*)secData.data();
    numElems = (secData.size() / sizeof(Elf64_Sym));
    data.assign(buf, buf + numElems);

    if (sort) std::sort(data.begin(), data.end(), symCompare);
    return 0;
}

static enum bpf_prog_type getSectionType(string& name) {
    for (int i = 0; sectionNameTypes[i].type != BPF_PROG_TYPE_UNSPEC; i++)
        if (StartsWith(name, sectionNameTypes[i].name)) return sectionNameTypes[i].type;

    return BPF_PROG_TYPE_UNSPEC;
}

/* If ever needed
static string getSectionName(enum bpf_prog_type type)
{
    for (int i = 0; sectionNameTypes[i].type != BPF_PROG_TYPE_UNSPEC; i++)
        if (sectionNameTypes[i].type == type)
            return string(sectionNameTypes[i].name);

    return NULL;
}
*/

static bool isRelSection(codeSection& cs, string& name) {
    for (int i = 0; sectionNameTypes[i].type != BPF_PROG_TYPE_UNSPEC; i++) {
        sectionType st = sectionNameTypes[i];

        if (st.type != cs.type) continue;

        if (StartsWith(name, string(".rel") + st.name + "/"))
            return true;
        else
            return false;
    }
    return false;
}

static int readProgDefs(ifstream& elfFile, vector<struct bpf_prog_def>& pd,
                        size_t sizeOfBpfProgDef) {
    vector<char> pdData;
    int ret = readSectionByName("progs", elfFile, pdData);
    // Older file formats do not require a 'progs' section at all.
    // (We should probably figure out whether this is behaviour which is safe to remove now.)
    if (ret == -2) return 0;
    if (ret) return ret;

    if (pdData.size() % sizeOfBpfProgDef) {
        ALOGE("readProgDefs failed due to improper sized progs section, %zu %% %zu != 0\n",
              pdData.size(), sizeOfBpfProgDef);
        return -1;
    };

    int progCount = pdData.size() / sizeOfBpfProgDef;
    pd.resize(progCount);
    size_t trimmedSize = std::min(sizeOfBpfProgDef, sizeof(struct bpf_prog_def));

    const char* dataPtr = pdData.data();
    for (auto& p : pd) {
        // First we zero initialize
        memset(&p, 0, sizeof(p));
        // Then we set non-zero defaults
        p.bpfloader_max_ver = DEFAULT_BPFLOADER_MAX_VER;  // v1.0
        // Then we copy over the structure prefix from the ELF file.
        memcpy(&p, dataPtr, trimmedSize);
        // Move to next struct in the ELF file
        dataPtr += sizeOfBpfProgDef;
    }
    return 0;
}

static int getSectionSymNames(ifstream& elfFile, const string& sectionName, vector<string>& names) {
    int ret;
    string name;
    vector<Elf64_Sym> symtab;
    vector<Elf64_Shdr> shTable;

    ret = readSymTab(elfFile, 1 /* sort */, symtab);
    if (ret) return ret;

    /* Get index of section */
    ret = readSectionHeadersAll(elfFile, shTable);
    if (ret) return ret;

    int sec_idx = -1;
    for (int i = 0; i < (int)shTable.size(); i++) {
        ret = getSymName(elfFile, shTable[i].sh_name, name);
        if (ret) return ret;

        if (!name.compare(sectionName)) {
            sec_idx = i;
            break;
        }
    }

    /* No section found with matching name*/
    if (sec_idx == -1) {
        ALOGW("No %s section could be found in elf object\n", sectionName.c_str());
        return -1;
    }

    for (int i = 0; i < (int)symtab.size(); i++) {
        if (symtab[i].st_shndx == sec_idx) {
            string s;
            ret = getSymName(elfFile, symtab[i].st_name, s);
            if (ret) return ret;
            names.push_back(s);
        }
    }

    return 0;
}

/* Read a section by its index - for ex to get sec hdr strtab blob */
static int readCodeSections(ifstream& elfFile, vector<codeSection>& cs, size_t sizeOfBpfProgDef) {
    vector<Elf64_Shdr> shTable;
    int entries, ret = 0;

    ret = readSectionHeadersAll(elfFile, shTable);
    if (ret) return ret;
    entries = shTable.size();

    vector<struct bpf_prog_def> pd;
    ret = readProgDefs(elfFile, pd, sizeOfBpfProgDef);
    if (ret) return ret;
    vector<string> progDefNames;
    ret = getSectionSymNames(elfFile, "progs", progDefNames);
    if (!pd.empty() && ret) return ret;

    for (int i = 0; i < entries; i++) {
        string name;
        codeSection cs_temp;
        cs_temp.type = BPF_PROG_TYPE_UNSPEC;

        ret = getSymName(elfFile, shTable[i].sh_name, name);
        if (ret) return ret;

        enum bpf_prog_type ptype = getSectionType(name);
        if (ptype != BPF_PROG_TYPE_UNSPEC) {
            string oldName = name;

            // convert all slashes to underscores
            std::replace(name.begin(), name.end(), '/', '_');

            cs_temp.type = ptype;
            cs_temp.name = name;

            ret = readSectionByIdx(elfFile, i, cs_temp.data);
            if (ret) return ret;
            ALOGD("Loaded code section %d (%s)\n", i, name.c_str());

            vector<string> csSymNames;
            ret = getSectionSymNames(elfFile, oldName, csSymNames);
            if (ret || !csSymNames.size()) return ret;
            for (size_t i = 0; i < progDefNames.size(); ++i) {
                if (!progDefNames[i].compare(csSymNames[0] + "_def")) {
                    cs_temp.prog_def = pd[i];
                    break;
                }
            }
        }

        /* Check for rel section */
        if (cs_temp.data.size() > 0 && i < entries) {
            ret = getSymName(elfFile, shTable[i + 1].sh_name, name);
            if (ret) return ret;

            if (isRelSection(cs_temp, name)) {
                ret = readSectionByIdx(elfFile, i + 1, cs_temp.rel_data);
                if (ret) return ret;
                ALOGD("Loaded relo section %d (%s)\n", i, name.c_str());
            }
        }

        if (cs_temp.data.size() > 0) {
            cs.push_back(std::move(cs_temp));
            ALOGD("Adding section %d to cs list\n", i);
        }
    }
    return 0;
}

static int getSymNameByIdx(ifstream& elfFile, int index, string& name) {
    vector<Elf64_Sym> symtab;
    int ret = 0;

    ret = readSymTab(elfFile, 0 /* !sort */, symtab);
    if (ret) return ret;

    if (index >= (int)symtab.size()) return -1;

    return getSymName(elfFile, symtab[index].st_name, name);
}

static int createMaps(const char* elfPath, ifstream& elfFile, vector<unique_fd>& mapFds,
                      const char* prefix, size_t sizeOfBpfMapDef) {
    int ret;
    vector<char> mdData;
    vector<struct bpf_map_def> md;
    vector<string> mapNames;
    string fname = pathToFilename(string(elfPath), true);

    ret = readSectionByName("maps", elfFile, mdData);
    if (ret == -2) return 0;  // no maps to read
    if (ret) return ret;

    if (mdData.size() % sizeOfBpfMapDef) {
        ALOGE("createMaps failed due to improper sized maps section, %zu %% %zu != 0\n",
              mdData.size(), sizeOfBpfMapDef);
        return -1;
    };

    int mapCount = mdData.size() / sizeOfBpfMapDef;
    md.resize(mapCount);
    size_t trimmedSize = std::min(sizeOfBpfMapDef, sizeof(struct bpf_map_def));

    const char* dataPtr = mdData.data();
    for (auto& m : md) {
        // First we zero initialize
        memset(&m, 0, sizeof(m));
        // Then we set non-zero defaults
        m.bpfloader_max_ver = DEFAULT_BPFLOADER_MAX_VER;  // v1.0
        m.max_kver = 0xFFFFFFFFu;                         // matches KVER_INF from bpf_helpers.h
        // Then we copy over the structure prefix from the ELF file.
        memcpy(&m, dataPtr, trimmedSize);
        // Move to next struct in the ELF file
        dataPtr += sizeOfBpfMapDef;
    }

    ret = getSectionSymNames(elfFile, "maps", mapNames);
    if (ret) return ret;

    unsigned kvers = kernelVersion();

    for (int i = 0; i < (int)mapNames.size(); i++) {
        if (BPFLOADER_VERSION < md[i].bpfloader_min_ver) {
            ALOGI("skipping map %s which requires bpfloader min ver 0x%05x\n", mapNames[i].c_str(),
                  md[i].bpfloader_min_ver);
            mapFds.push_back(unique_fd());
            continue;
        }

        if (BPFLOADER_VERSION >= md[i].bpfloader_max_ver) {
            ALOGI("skipping map %s which requires bpfloader max ver 0x%05x\n", mapNames[i].c_str(),
                  md[i].bpfloader_max_ver);
            mapFds.push_back(unique_fd());
            continue;
        }

        if (kvers < md[i].min_kver) {
            ALOGI("skipping map %s which requires kernel version 0x%x >= 0x%x\n",
                  mapNames[i].c_str(), kvers, md[i].min_kver);
            mapFds.push_back(unique_fd());
            continue;
        }

        if (kvers >= md[i].max_kver) {
            ALOGI("skipping map %s which requires kernel version 0x%x < 0x%x\n",
                  mapNames[i].c_str(), kvers, md[i].max_kver);
            mapFds.push_back(unique_fd());
            continue;
        }

        // Format of pin location is /sys/fs/bpf/<prefix>map_<filename>_<mapname>
        string mapPinLoc =
                string(BPF_FS_PATH) + prefix + "map_" + fname + "_" + string(mapNames[i]);
        bool reuse = false;
        unique_fd fd;
        int saved_errno;

        if (access(mapPinLoc.c_str(), F_OK) == 0) {
            fd.reset(bpf_obj_get(mapPinLoc.c_str()));
            saved_errno = errno;
            ALOGD("bpf_create_map reusing map %s, ret: %d\n", mapNames[i].c_str(), fd.get());
            reuse = true;
        } else {
            enum bpf_map_type type = md[i].type;
            if (type == BPF_MAP_TYPE_DEVMAP && !isAtLeastKernelVersion(4, 14, 0)) {
                // On Linux Kernels older than 4.14 this map type doesn't exist, but it can kind
                // of be approximated: ARRAY has the same userspace api, though it is not usable
                // by the same ebpf programs.  However, that's okay because the bpf_redirect_map()
                // helper doesn't exist on 4.9 anyway (so the bpf program would fail to load,
                // and thus needs to be tagged as 4.14+ either way), so there's nothing useful you
                // could do with a DEVMAP anyway (that isn't already provided by an ARRAY)...
                // Hence using an ARRAY instead of a DEVMAP simply makes life easier for userspace.
                type = BPF_MAP_TYPE_ARRAY;
            }
            if (type == BPF_MAP_TYPE_DEVMAP_HASH && !isAtLeastKernelVersion(5, 4, 0)) {
                // On Linux Kernels older than 5.4 this map type doesn't exist, but it can kind
                // of be approximated: HASH has the same userspace visible api.
                // However it cannot be used by ebpf programs in the same way.
                // Since bpf_redirect_map() only requires 4.14, a program using a DEVMAP_HASH map
                // would fail to load (due to trying to redirect to a HASH instead of DEVMAP_HASH).
                // One must thus tag any BPF_MAP_TYPE_DEVMAP_HASH + bpf_redirect_map() using
                // programs as being 5.4+...
                type = BPF_MAP_TYPE_HASH;
            }
            fd.reset(bpf_create_map(type, mapNames[i].c_str(), md[i].key_size, md[i].value_size,
                                    md[i].max_entries, md[i].map_flags));
            saved_errno = errno;
            ALOGD("bpf_create_map name %s, ret: %d\n", mapNames[i].c_str(), fd.get());
        }

        if (fd < 0) return -saved_errno;

        if (!reuse) {
            ret = bpf_obj_pin(fd, mapPinLoc.c_str());
            if (ret) return -errno;
            ret = chown(mapPinLoc.c_str(), (uid_t)md[i].uid, (gid_t)md[i].gid);
            if (ret) return -errno;
            ret = chmod(mapPinLoc.c_str(), md[i].mode);
            if (ret) return -errno;
        }

        mapFds.push_back(std::move(fd));
    }

    return ret;
}

/* For debugging, dump all instructions */
static void dumpIns(char* ins, int size) {
    for (int row = 0; row < size / 8; row++) {
        ALOGE("%d: ", row);
        for (int j = 0; j < 8; j++) {
            ALOGE("%3x ", ins[(row * 8) + j]);
        }
        ALOGE("\n");
    }
}

/* For debugging, dump all code sections from cs list */
static void dumpAllCs(vector<codeSection>& cs) {
    for (int i = 0; i < (int)cs.size(); i++) {
        ALOGE("Dumping cs %d, name %s\n", int(i), cs[i].name.c_str());
        dumpIns((char*)cs[i].data.data(), cs[i].data.size());
        ALOGE("-----------\n");
    }
}

static void applyRelo(void* insnsPtr, Elf64_Addr offset, int fd) {
    int insnIndex;
    struct bpf_insn *insn, *insns;

    insns = (struct bpf_insn*)(insnsPtr);

    insnIndex = offset / sizeof(struct bpf_insn);
    insn = &insns[insnIndex];

    ALOGD(
        "applying relo to instruction at byte offset: %d, \
	       insn offset %d , insn %lx\n",
        (int)offset, (int)insnIndex, *(unsigned long*)insn);

    if (insn->code != (BPF_LD | BPF_IMM | BPF_DW)) {
        ALOGE("Dumping all instructions till ins %d\n", insnIndex);
        ALOGE("invalid relo for insn %d: code 0x%x\n", insnIndex, insn->code);
        dumpIns((char*)insnsPtr, (insnIndex + 3) * 8);
        return;
    }

    insn->imm = fd;
    insn->src_reg = BPF_PSEUDO_MAP_FD;
}

static void applyMapRelo(ifstream& elfFile, vector<unique_fd> &mapFds, vector<codeSection>& cs) {
    vector<string> mapNames;

    int ret = getSectionSymNames(elfFile, "maps", mapNames);
    if (ret) return;

    for (int k = 0; k != (int)cs.size(); k++) {
        Elf64_Rel* rel = (Elf64_Rel*)(cs[k].rel_data.data());
        int n_rel = cs[k].rel_data.size() / sizeof(*rel);

        for (int i = 0; i < n_rel; i++) {
            int symIndex = ELF64_R_SYM(rel[i].r_info);
            string symName;

            ret = getSymNameByIdx(elfFile, symIndex, symName);
            if (ret) return;

            /* Find the map fd and apply relo */
            for (int j = 0; j < (int)mapNames.size(); j++) {
                if (!mapNames[j].compare(symName)) {
                    applyRelo(cs[k].data.data(), rel[i].r_offset, mapFds[j]);
                    break;
                }
            }
        }
    }
}

static int loadCodeSections(const char* elfPath, vector<codeSection>& cs, const string& license,
                            const char* prefix) {
    unsigned kvers = kernelVersion();
    int ret, fd;

    if (!kvers) return -1;

    string fname = pathToFilename(string(elfPath), true);

    for (int i = 0; i < (int)cs.size(); i++) {
        string name = cs[i].name;
        unsigned bpfMinVer = DEFAULT_BPFLOADER_MIN_VER;  // v0.0
        unsigned bpfMaxVer = DEFAULT_BPFLOADER_MAX_VER;  // v1.0

        if (cs[i].prog_def.has_value()) {
            unsigned min_kver = cs[i].prog_def->min_kver;
            unsigned max_kver = cs[i].prog_def->max_kver;
            ALOGD("cs[%d].name:%s min_kver:%x .max_kver:%x (kvers:%x)\n", i, name.c_str(), min_kver,
                  max_kver, kvers);
            if (kvers < min_kver) continue;
            if (kvers >= max_kver) continue;

            bpfMinVer = cs[i].prog_def->bpfloader_min_ver;
            bpfMaxVer = cs[i].prog_def->bpfloader_max_ver;
        }

        ALOGD("cs[%d].name:%s requires bpfloader version [0x%05x,0x%05x)\n", i, name.c_str(),
              bpfMinVer, bpfMaxVer);
        if (BPFLOADER_VERSION < bpfMinVer) continue;
        if (BPFLOADER_VERSION >= bpfMaxVer) continue;

        // strip any potential $foo suffix
        // this can be used to provide duplicate programs
        // conditionally loaded based on running kernel version
        name = name.substr(0, name.find_last_of('$'));

        bool reuse = false;
        // Format of pin location is
        // /sys/fs/bpf/<prefix>prog_<filename>_<mapname>
        string progPinLoc = BPF_FS_PATH;
        progPinLoc += prefix;
        progPinLoc += "prog_";
        progPinLoc += fname;
        progPinLoc += '_';
        progPinLoc += name;
        if (access(progPinLoc.c_str(), F_OK) == 0) {
            fd = retrieveProgram(progPinLoc.c_str());
            ALOGD("New bpf prog load reusing prog %s, ret: %d (%s)\n", progPinLoc.c_str(), fd,
                  (fd < 0 ? std::strerror(errno) : "no error"));
            reuse = true;
        } else {
            vector<char> log_buf(BPF_LOAD_LOG_SZ, 0);

            fd = bpf_prog_load(cs[i].type, name.c_str(), (struct bpf_insn*)cs[i].data.data(),
                               cs[i].data.size(), license.c_str(), kvers, 0, log_buf.data(),
                               log_buf.size());
            ALOGD("bpf_prog_load lib call for %s (%s) returned fd: %d (%s)\n", elfPath,
                  cs[i].name.c_str(), fd, (fd < 0 ? std::strerror(errno) : "no error"));

            if (fd < 0) {
                vector<string> lines = android::base::Split(log_buf.data(), "\n");

                ALOGW("bpf_prog_load - BEGIN log_buf contents:");
                for (const auto& line : lines) ALOGW("%s", line.c_str());
                ALOGW("bpf_prog_load - END log_buf contents.");

                if (cs[i].prog_def->optional) {
                    ALOGW("failed program is marked optional - continuing...");
                    continue;
                }
                ALOGE("non-optional program failed to load.");
            }
        }

        if (fd < 0) return fd;
        if (fd == 0) return -EINVAL;

        if (!reuse) {
            ret = bpf_obj_pin(fd, progPinLoc.c_str());
            if (ret) return -errno;
            if (cs[i].prog_def.has_value()) {
                if (chown(progPinLoc.c_str(), (uid_t)cs[i].prog_def->uid,
                          (gid_t)cs[i].prog_def->gid)) {
                    return -errno;
                }
            }
            if (chmod(progPinLoc.c_str(), 0440)) return -errno;
        }

        cs[i].prog_fd.reset(fd);
    }

    return 0;
}

int loadProg(const char* elfPath, bool* isCritical, const char* prefix) {
    vector<char> license;
    vector<char> critical;
    vector<codeSection> cs;
    vector<unique_fd> mapFds;
    int ret;

    if (!isCritical) return -1;
    *isCritical = false;

    ifstream elfFile(elfPath, ios::in | ios::binary);
    if (!elfFile.is_open()) return -1;

    ret = readSectionByName("critical", elfFile, critical);
    *isCritical = !ret;

    ret = readSectionByName("license", elfFile, license);
    if (ret) {
        ALOGE("Couldn't find license in %s\n", elfPath);
        return ret;
    } else {
        ALOGD("Loading %s%s ELF object %s with license %s\n",
              *isCritical ? "critical for " : "optional", *isCritical ? (char*)critical.data() : "",
              elfPath, (char*)license.data());
    }

    // the following default values are for bpfloader V0.0 format which does not include them
    unsigned int bpfLoaderMinVer =
            readSectionUint("bpfloader_min_ver", elfFile, DEFAULT_BPFLOADER_MIN_VER);
    unsigned int bpfLoaderMaxVer =
            readSectionUint("bpfloader_max_ver", elfFile, DEFAULT_BPFLOADER_MAX_VER);
    size_t sizeOfBpfMapDef =
            readSectionUint("size_of_bpf_map_def", elfFile, DEFAULT_SIZEOF_BPF_MAP_DEF);
    size_t sizeOfBpfProgDef =
            readSectionUint("size_of_bpf_prog_def", elfFile, DEFAULT_SIZEOF_BPF_PROG_DEF);

    // inclusive lower bound check
    if (BPFLOADER_VERSION < bpfLoaderMinVer) {
        ALOGI("BpfLoader version 0x%05x ignoring ELF object %s with min ver 0x%05x\n",
              BPFLOADER_VERSION, elfPath, bpfLoaderMinVer);
        return 0;
    }

    // exclusive upper bound check
    if (BPFLOADER_VERSION >= bpfLoaderMaxVer) {
        ALOGI("BpfLoader version 0x%05x ignoring ELF object %s with max ver 0x%05x\n",
              BPFLOADER_VERSION, elfPath, bpfLoaderMaxVer);
        return 0;
    }

    ALOGI("BpfLoader version 0x%05x processing ELF object %s with ver [0x%05x,0x%05x)\n",
          BPFLOADER_VERSION, elfPath, bpfLoaderMinVer, bpfLoaderMaxVer);

    if (sizeOfBpfMapDef < DEFAULT_SIZEOF_BPF_MAP_DEF) {
        ALOGE("sizeof(bpf_map_def) of %zu is too small (< %d)\n", sizeOfBpfMapDef,
              DEFAULT_SIZEOF_BPF_MAP_DEF);
        return -1;
    }

    if (sizeOfBpfProgDef < DEFAULT_SIZEOF_BPF_PROG_DEF) {
        ALOGE("sizeof(bpf_prog_def) of %zu is too small (< %d)\n", sizeOfBpfProgDef,
              DEFAULT_SIZEOF_BPF_PROG_DEF);
        return -1;
    }

    ret = readCodeSections(elfFile, cs, sizeOfBpfProgDef);
    if (ret) {
        ALOGE("Couldn't read all code sections in %s\n", elfPath);
        return ret;
    }

    /* Just for future debugging */
    if (0) dumpAllCs(cs);

    ret = createMaps(elfPath, elfFile, mapFds, prefix, sizeOfBpfMapDef);
    if (ret) {
        ALOGE("Failed to create maps: (ret=%d) in %s\n", ret, elfPath);
        return ret;
    }

    for (int i = 0; i < (int)mapFds.size(); i++)
        ALOGD("map_fd found at %d is %d in %s\n", i, mapFds[i].get(), elfPath);

    applyMapRelo(elfFile, mapFds, cs);

    ret = loadCodeSections(elfPath, cs, string(license.data()), prefix);
    if (ret) ALOGE("Failed to load programs, loadCodeSections ret=%d\n", ret);

    return ret;
}

}  // namespace bpf
}  // namespace android
