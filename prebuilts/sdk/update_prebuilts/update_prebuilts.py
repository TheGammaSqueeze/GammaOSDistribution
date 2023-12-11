#!/usr/bin/python3

# This script is used to update platform SDK prebuilts, Support Library, and a variety of other
# prebuilt libraries used by Android's Makefile builds. For details on how to use this script,
# visit go/update-prebuilts.
import os, sys, getopt, zipfile, re
import argparse
import glob
import subprocess
from shutil import copyfile, rmtree, which, move
from distutils.version import LooseVersion
from functools import reduce
import six
import urllib.request, urllib.parse, urllib.error

current_path = 'current'
framework_sdk_target = 'sdk_phone_armv7-win_sdk'
androidx_dir = os.path.join(current_path, 'androidx')
gmaven_dir = os.path.join(current_path, 'gmaven')
extras_dir = os.path.join(current_path, 'extras')
buildtools_dir = 'tools'
jetifier_dir = os.path.join(buildtools_dir, 'jetifier', 'jetifier-standalone')

temp_dir = os.path.join(os.getcwd(), "support_tmp")
os.chdir(os.path.dirname(os.path.dirname(os.path.realpath(sys.argv[0]))))
git_dir = os.getcwd()

# See go/fetch_artifact for details on this script.
FETCH_ARTIFACT = '/google/data/ro/projects/android/fetch_artifact'
FETCH_ARTIFACT_BEYOND_CORP = '/usr/bin/fetch_artifact'

# See (https://developer.android.com/studio/build/dependencies#gmaven-access)
GMAVEN_BASE_URL = 'https://maven.google.com'

# Leave map blank to automatically populate name and path:
# - Name format is MAVEN.replaceAll(':','_')
# - Path format is MAVEN.replaceAll(':','/').replaceAll('.','/')
maven_to_make = {
    # AndroidX
    'androidx.benchmark:benchmark-macro': { },
    'androidx.benchmark:benchmark-macro-junit4': { },
    'androidx.benchmark:benchmark-common': { },
    'androidx.benchmark:benchmark-junit4': { },
    'androidx.tracing:tracing': { },
    'androidx.tracing:tracing-ktx': { },
    'androidx.slice:slice-builders': { },
    'androidx.slice:slice-core': { },
    'androidx.slice:slice-view': { },
    'androidx.remotecallback:remotecallback': { },
    'androidx.remotecallback:remotecallback-processor': {'host':True},
    'androidx.versionedparcelable:versionedparcelable': { },
    'androidx.vectordrawable:vectordrawable-animated': { },
    'androidx.activity:activity': { },
    'androidx.activity:activity-ktx': { },
    'androidx.annotation:annotation': {'host_and_device':True},
    'androidx.annotation:annotation-experimental': { },
    'androidx.asynclayoutinflater:asynclayoutinflater': { },
    'androidx.collection:collection': { },
    'androidx.collection:collection-ktx': { },
    'androidx.concurrent:concurrent-futures': { },
    'androidx.concurrent:concurrent-listenablefuture-callback': { },
    'androidx.concurrent:concurrent-listenablefuture': { },
    'androidx.core:core': { },
    'androidx.core:core-animation': { },
    'androidx.core:core-ktx': { },
    'androidx.contentpaging:contentpaging': { },
    'androidx.coordinatorlayout:coordinatorlayout': { },
    'androidx.legacy:legacy-support-core-ui': { },
    'androidx.legacy:legacy-support-core-utils': { },
    'androidx.cursoradapter:cursoradapter': { },
    'androidx.browser:browser': { },
    'androidx.customview:customview': { },
    'androidx.documentfile:documentfile': { },
    'androidx.drawerlayout:drawerlayout': { },
    'androidx.dynamicanimation:dynamicanimation': { },
    'androidx.emoji:emoji': { },
    'androidx.emoji:emoji-appcompat': { },
    'androidx.emoji:emoji-bundled': { },
    'androidx.emoji2:emoji2': { },
    'androidx.emoji2:emoji2-views-helper': { },
    'androidx.exifinterface:exifinterface': { },
    'androidx.fragment:fragment': { },
    'androidx.fragment:fragment-ktx': { },
    'androidx.heifwriter:heifwriter': { },
    'androidx.interpolator:interpolator': { },
    'androidx.loader:loader': { },
    'androidx.localbroadcastmanager:localbroadcastmanager': { },
    'androidx.media:media': { },
    'androidx.media2:media2-player': { },
    'androidx.media2:media2-session': { },
    'androidx.media2:media2-common': { },
    'androidx.media2:media2-exoplayer': { },
    'androidx.media2:media2-widget': { },
    'androidx.navigation:navigation-common': { },
    'androidx.navigation:navigation-common-ktx': { },
    'androidx.navigation:navigation-fragment': { },
    'androidx.navigation:navigation-fragment-ktx': { },
    'androidx.navigation:navigation-runtime': { },
    'androidx.navigation:navigation-runtime-ktx': { },
    'androidx.navigation:navigation-ui': { },
    'androidx.navigation:navigation-ui-ktx': { },
    'androidx.percentlayout:percentlayout': { },
    'androidx.print:print': { },
    'androidx.recommendation:recommendation': { },
    'androidx.recyclerview:recyclerview-selection': { },
    'androidx.savedstate:savedstate': { },
    'androidx.savedstate:savedstate-ktx': { },
    'androidx.slidingpanelayout:slidingpanelayout': { },
    'androidx.swiperefreshlayout:swiperefreshlayout': { },
    'androidx.textclassifier:textclassifier': { },
    'androidx.transition:transition': { },
    'androidx.tvprovider:tvprovider': { },
    'androidx.legacy:legacy-support-v13': { },
    'androidx.legacy:legacy-preference-v14': { },
    'androidx.leanback:leanback': { },
    'androidx.leanback:leanback-preference': { },
    'androidx.legacy:legacy-support-v4': { },
    'androidx.appcompat:appcompat': { },
    'androidx.appcompat:appcompat-resources': { },
    'androidx.cardview:cardview': { },
    'androidx.gridlayout:gridlayout': { },
    'androidx.mediarouter:mediarouter': { },
    'androidx.palette:palette': { },
    'androidx.preference:preference': { },
    'androidx.recyclerview:recyclerview': { },
    'androidx.vectordrawable:vectordrawable': { },
    'androidx.viewpager:viewpager': { },
    'androidx.viewpager2:viewpager2': { },
    'androidx.wear:wear': { },
    'androidx.wear:wear-ongoing': { },
    'androidx.webkit:webkit': { },
    'androidx.biometric:biometric': { },
    'androidx.autofill:autofill': { },
    'androidx.appsearch:appsearch': { },
    'androidx.appsearch:appsearch-local-storage': {'name':'androidx.appsearch_appsearch_local_storage'},
    'androidx.appsearch:appsearch-platform-storage': { },
    'androidx.appsearch:appsearch-compiler': {'name':'androidx.appsearch_appsearch-compiler', 'host':True},
    'androidx.car.app:app': { },
    'androidx.car.app:app-automotive': { },
    'androidx.car.app:app-testing': { },
    'androidx.startup:startup-runtime': { },
    'androidx.resourceinspection:resourceinspection-annotation': { },
    'androidx.profileinstaller:profileinstaller': { },

    # AndroidX for Compose
    'androidx.compose.compiler:compiler-hosted': { 'host':True },
    'androidx.compose.runtime:runtime': { },
    'androidx.compose.runtime:runtime-saveable': { },
    'androidx.compose.foundation:foundation': { },
    'androidx.compose.foundation:foundation-layout': { },
    'androidx.compose.foundation:foundation-text': { },
    'androidx.compose.ui:ui': { },
    'androidx.compose.ui:ui-geometry': { },
    'androidx.compose.ui:ui-graphics': { },
    'androidx.compose.ui:ui-text': { },
    'androidx.compose.ui:ui-unit': { },
    'androidx.compose.ui:ui-util': { },
    'androidx.compose.animation:animation-core': { },
    'androidx.compose.animation:animation': { },
    'androidx.compose.material:material-icons-core': { },
    'androidx.compose.material:material-ripple': { },
    'androidx.compose.material:material': { },
    'androidx.activity:activity-compose': { },

    # AndroidX for Multidex
    'androidx.multidex:multidex': { },
    'androidx.multidex:multidex-instrumentation': { },

    # AndroidX for Constraint Layout
    'androidx.constraintlayout:constraintlayout': {'name':'androidx-constraintlayout_constraintlayout'},
    'androidx.constraintlayout:constraintlayout-solver': {'name':'androidx-constraintlayout_constraintlayout-solver'},

    # AndroidX for Architecture Components
    'androidx.arch.core:core-common': { },
    'androidx.arch.core:core-runtime': { },
    'androidx.lifecycle:lifecycle-common': { },
    'androidx.lifecycle:lifecycle-common-java8': { },
    'androidx.lifecycle:lifecycle-extensions': { },
    'androidx.lifecycle:lifecycle-livedata': { },
    'androidx.lifecycle:lifecycle-livedata-ktx': { },
    'androidx.lifecycle:lifecycle-livedata-core': { },
    'androidx.lifecycle:lifecycle-livedata-core-ktx': { },
    'androidx.lifecycle:lifecycle-process': { },
    'androidx.lifecycle:lifecycle-runtime': { },
    'androidx.lifecycle:lifecycle-runtime-ktx': { },
    'androidx.lifecycle:lifecycle-service': { },
    'androidx.lifecycle:lifecycle-viewmodel': { },
    'androidx.lifecycle:lifecycle-viewmodel-ktx': { },
    'androidx.lifecycle:lifecycle-viewmodel-savedstate': { },
    'androidx.paging:paging-common': { },
    'androidx.paging:paging-common-ktx': { },
    'androidx.paging:paging-runtime': { },
    'androidx.sqlite:sqlite': { },
    'androidx.sqlite:sqlite-framework': { },
    'androidx.room:room-common': {'host_and_device':True},
    'androidx.room:room-compiler': {'host':True, 'extra-static-libs':{'guava-21.0'}},
    'androidx.room:room-migration': {'host_and_device':True},
    'androidx.room:room-runtime': { },
    'androidx.room:room-testing': { },
    'androidx.room:room-compiler-processing': {'host':True},
    'androidx.work:work-runtime': { },
    'androidx.work:work-runtime-ktx': { },
    'androidx.work:work-testing': { },

    # Third-party dependencies
    'com.google.android:flexbox': {'name':'flexbox', 'path':'flexbox'},

    # Androidx Material Design Components
    'com.google.android.material:material': { },
}

# Mapping of POM dependencies to Soong build targets
deps_rewrite = {
    'auto-common':'auto_common',
    'auto-value-annotations':'auto_value_annotations',
    'com.google.auto.value:auto-value':'auto_value_plugin',
    'monitor':'androidx.test.monitor',
    'rules':'androidx.test.rules',
    'runner':'androidx.test.runner',
    'androidx.test:core':'androidx.test.core',
    'com.squareup:javapoet':'javapoet',
    'com.google.guava:listenablefuture':'guava-listenablefuture-prebuilt-jar',
    'sqlite-jdbc':'xerial-sqlite-jdbc',
    'gson':'gson-prebuilt-jar',
    'com.intellij:annotations':'jetbrains-annotations',
    'javax.annotation:javax.annotation-api':'javax-annotation-api-prebuilt-host-jar',
    'org.robolectric:robolectric':'Robolectric_all-target',
    'org.jetbrains.kotlin:kotlin-stdlib-common':'kotlin-stdlib',
    'org.jetbrains.kotlinx:kotlinx-coroutines-core':'kotlinx_coroutines',
    'org.jetbrains.kotlinx:kotlinx-coroutines-android':'kotlinx_coroutines_android',
    'org.jetbrains.kotlinx:kotlinx-metadata-jvm':'kotlinx_metadata_jvm',
}

# List of artifacts that will be updated from GMaven
# Use pattern: `group:library:version:extension`
# e.g.:
#   androidx.appcompat:appcompat:1.2.0:aar
# Use `latest` to always fetch the latest version.
# e.g.:
#   androidx.appcompat:appcompat:latest:aar
# Also make sure you add `group:library`:{} to maven_to_make as well.
gmaven_artifacts = {}

def name_for_artifact(group_artifact):
    return group_artifact.replace(':','_')


def path_for_artifact(group_artifact):
    return group_artifact.replace('.','/').replace(':','/')


# Add automatic entries to maven_to_make.
for key in maven_to_make:
    if ('name' not in maven_to_make[key]):
        maven_to_make[key]['name'] = name_for_artifact(key)
    if ('path' not in maven_to_make[key]):
        maven_to_make[key]['path'] = path_for_artifact(key)

# Always remove these files.
blacklist_files = [
    'annotations.zip',
    'public.txt',
    'R.txt',
    'AndroidManifest.xml',
    os.path.join('libs','noto-emoji-compat-java.jar')
]

artifact_pattern = re.compile(r"^(.+?)-(\d+\.\d+\.\d+(?:-\w+\d+)?(?:-[\d.]+)*)\.(jar|aar)$")


class MavenLibraryInfo:
    def __init__(self, key, group_id, artifact_id, version, dir, repo_dir, file):
        self.key = key
        self.group_id = group_id
        self.artifact_id = artifact_id
        self.version = version
        self.dir = dir
        self.repo_dir = repo_dir
        self.file = file


def print_e(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)


def touch(fname, times=None):
    with open(fname, 'a'):
        os.utime(fname, times)


def path(*path_parts):
    return reduce((lambda x, y: os.path.join(x, y)), path_parts)


def flatten(list):
    return reduce((lambda x, y: "%s %s" % (x, y)), list)


def rm(path):
    if os.path.isdir(path):
        rmtree(path)
    elif os.path.exists(path):
        os.remove(path)


def mv(src_path, dst_path):
    if os.path.exists(dst_path):
        rm(dst_path)
    if not os.path.exists(os.path.dirname(dst_path)):
        os.makedirs(os.path.dirname(dst_path))
    for f in (glob.glob(src_path)):
        if '*' in dst_path:
            dst = os.path.join(os.path.dirname(dst_path), os.path.basename(f))
        else:
            dst = dst_path
        move(f, dst)


def detect_artifacts(maven_repo_dirs):
    maven_lib_info = {}

    # Find the latest revision for each artifact, remove others
    for repo_dir in maven_repo_dirs:
        for root, dirs, files in os.walk(repo_dir):
            for file in files:
                if file[-4:] == ".pom":
                    # Read the POM (hack hack hack).
                    group_id = ''
                    artifact_id = ''
                    version = ''
                    file = os.path.join(root, file)
                    with open(file) as pom_file:
                        for line in pom_file:
                            if line[:11] == '  <groupId>':
                                group_id = line[11:-11]
                            elif line[:14] == '  <artifactId>':
                                artifact_id = line[14:-14]
                            elif line[:11] == '  <version>':
                                version = line[11:-11]
                    if group_id == '' or artifact_id == '' or version == '':
                        print_e('Failed to find Maven artifact data in ' + file)
                        continue

                    # Locate the artifact.
                    artifact_file = file[:-4]
                    if os.path.exists(artifact_file + '.jar'):
                        artifact_file = artifact_file + '.jar'
                    elif os.path.exists(artifact_file + '.aar'):
                        artifact_file = artifact_file + '.aar'
                    else:
                        print_e('Failed to find artifact for ' + artifact_file)
                        continue

                    # Make relative to root.
                    artifact_file = artifact_file[len(root) + 1:]

                    # Find the mapping.
                    group_artifact = group_id + ':' + artifact_id
                    if group_artifact in maven_to_make:
                        key = group_artifact
                    elif artifact_id in maven_to_make:
                        key = artifact_id
                    else:
                        # No mapping entry, skip this library.
                        continue

                    # Store the latest version.
                    version = LooseVersion(version)
                    if key not in maven_lib_info \
                            or version > maven_lib_info[key].version:
                        maven_lib_info[key] = MavenLibraryInfo(key, group_id, artifact_id, version,
                                                               root, repo_dir, artifact_file)

    return maven_lib_info


def transform_maven_repos(maven_repo_dirs, transformed_dir, extract_res=True, include_static_deps=True):
    cwd = os.getcwd()

    # Use a temporary working directory.
    maven_lib_info = detect_artifacts(maven_repo_dirs)
    working_dir = temp_dir

    if not maven_lib_info:
        print_e('Failed to detect artifacts')
        return False

    # extract some files (for example, AndroidManifest.xml) from any relevant artifacts
    for info in maven_lib_info.values():
        transform_maven_lib(working_dir, info, extract_res)

    # generate a single Android.bp that specifies to use all of the above artifacts
    makefile = os.path.join(working_dir, 'Android.bp')
    with open(makefile, 'w') as f:
        args = ["pom2bp"]
        args.extend(["-sdk-version", "31"])
        args.extend(["-default-min-sdk-version", "24"])
        if include_static_deps:
            args.append("-static-deps")
        rewriteNames = sorted([name for name in maven_to_make if ":" in name] + [name for name in maven_to_make if ":" not in name])
        args.extend(["-rewrite=^" + name + "$=" + maven_to_make[name]['name'] for name in rewriteNames])
        args.extend(["-rewrite=^" + key + "$=" + value for key, value in deps_rewrite.items()])
        args.extend(["-extra-static-libs=" + maven_to_make[name]['name'] + "=" + ",".join(sorted(maven_to_make[name]['extra-static-libs'])) for name in maven_to_make if 'extra-static-libs' in maven_to_make[name]])
        args.extend(["-optional-uses-libs=" + maven_to_make[name]['name'] + "=" + ",".join(sorted(maven_to_make[name]['optional-uses-libs'])) for name in maven_to_make if 'optional-uses-libs' in maven_to_make[name]])
        args.extend(["-host=" + name for name in maven_to_make if maven_to_make[name].get('host')])
        args.extend(["-host-and-device=" + name for name in maven_to_make if maven_to_make[name].get('host_and_device')])
        # these depend on GSON which is not in AOSP
        args.extend(["-exclude=android-arch-room-migration",
                     "-exclude=android-arch-room-testing"])
        args.extend(["."])
        subprocess.check_call(args, stdout=f, cwd=working_dir)

    # Replace the old directory.
    output_dir = os.path.join(cwd, transformed_dir)
    mv(working_dir, output_dir)
    return True

# moves <artifact_info> (of type MavenLibraryInfo) into the appropriate part of <working_dir> , and possibly unpacks any necessary included files
def transform_maven_lib(working_dir, artifact_info, extract_res):
    # Move library into working dir
    new_dir = os.path.normpath(os.path.join(working_dir, os.path.relpath(artifact_info.dir, artifact_info.repo_dir)))
    mv(artifact_info.dir, new_dir)

    matcher = artifact_pattern.match(artifact_info.file)
    maven_lib_name = artifact_info.key
    maven_lib_vers = matcher.group(2)
    maven_lib_type = artifact_info.file[-3:]

    group_artifact = artifact_info.key
    make_lib_name = maven_to_make[group_artifact]['name']
    make_dir_name = maven_to_make[group_artifact]['path']

    artifact_file = os.path.join(new_dir, artifact_info.file)

    if maven_lib_type == "aar":
        if extract_res:
            target_dir = os.path.join(working_dir, make_dir_name)
            if not os.path.exists(target_dir):
                os.makedirs(target_dir)

            process_aar(artifact_file, target_dir)

        with zipfile.ZipFile(artifact_file) as zip:
            manifests_dir = os.path.join(working_dir, "manifests")
            zip.extract("AndroidManifest.xml", os.path.join(manifests_dir, make_lib_name))

    print(maven_lib_vers, ":", maven_lib_name, "->", make_lib_name)


def process_aar(artifact_file, target_dir):
    # Extract AAR file to target_dir.
    with zipfile.ZipFile(artifact_file) as zip:
        zip.extractall(target_dir)

    # Remove classes.jar
    classes_jar = os.path.join(target_dir, "classes.jar")
    if os.path.exists(classes_jar):
        os.remove(classes_jar)

    # Remove or preserve empty dirs.
    for root, dirs, files in os.walk(target_dir):
        for dir in dirs:
            dir_path = os.path.join(root, dir)
            if not os.listdir(dir_path):
                os.rmdir(dir_path)

    # Remove top-level cruft.
    for file in blacklist_files:
        file_path = os.path.join(target_dir, file)
        if os.path.exists(file_path):
            os.remove(file_path)


class GMavenArtifact(object):
    # A map from group:library to the latest available version
    key_versions_map = {}
    def __init__(self, artifact_glob):
        try:
            (group, library, version, ext) = artifact_glob.split(':')
        except ValueError:
            raise ValueError(f'Error in {artifact_glob} expected: group:library:version:ext')

        if not group or not library or not version or not ext:
            raise ValueError(f'Error in {artifact_glob} expected: group:library:version:ext')

        self.group = group
        self.group_path = group.replace('.', '/')
        self.library = library
        self.key = f'{group}:{library}'
        self.version = version
        self.ext = ext

    def get_pom_file_url(self):
        return f'{GMAVEN_BASE_URL}/{self.group_path}/{self.library}/{self.version}/{self.library}-{self.version}.pom'

    def get_artifact_url(self):
        return f'{GMAVEN_BASE_URL}/{self.group_path}/{self.library}/{self.version}/{self.library}-{self.version}.{self.ext}'

    def get_latest_version(self):
        latest_version = GMavenArtifact.key_versions_map[self.key] \
                if self.key in GMavenArtifact.key_versions_map else None

        if not latest_version:
            print(f'Fetching latest version for {self.key}')
            group_index_url = f'{GMAVEN_BASE_URL}/{self.group_path}/group-index.xml'
            import xml.etree.ElementTree as ET
            tree = ET.parse(urllib.request.urlopen(group_index_url))
            root = tree.getroot()
            libraries = root.findall('./*[@versions]')
            for library in libraries:
                key = f'{root.tag}:{library.tag}'
                GMavenArtifact.key_versions_map[key] = library.get('versions').split(',')[-1]
            latest_version = GMavenArtifact.key_versions_map[self.key]
        return latest_version


def fetch_gmaven_artifact(artifact):
    """Fetch a GMaven artifact.

    Downloads a GMaven artifact
    (https://developer.android.com/studio/build/dependencies#gmaven-access)

    Args:
        artifact_glob: an instance of GMavenArtifact.
    """
    download_to = os.path.join('gmaven', artifact.group, artifact.library, artifact.version)

    _DownloadFileToDisk(artifact.get_pom_file_url(), os.path.join(download_to, f'{artifact.library}-{artifact.version}.pom'))
    _DownloadFileToDisk(artifact.get_artifact_url(), os.path.join(download_to, f'{artifact.library}-{artifact.version}.{artifact.ext}'))

    return download_to


def _DownloadFileToDisk(url, filepath):
    """Download the file at URL to the location dictated by the path.

    Args:
        url: Remote URL to download file from.
        filepath: Filesystem path to write the file to.
    """
    print(f'Downloading URL: {url}')
    file_data = urllib.request.urlopen(url)

    try:
        os.makedirs(os.path.dirname(filepath))
    except os.error:
        # This is a common situation - os.makedirs fails if dir already exists.
        pass
    try:
        with open(filepath, 'wb') as f:
            f.write(six.ensure_binary(file_data.read()))
    except:
        os.remove(os.path.dirname(filepath))
        raise


def fetch_artifact(target, build_id, artifact_path):
    global args
    download_to = os.path.join('.', os.path.dirname(artifact_path))
    print('Fetching %s from %s ...' % (artifact_path, target))
    if not os.path.exists(download_to):
        os.makedirs(download_to)
    if args.beyond_corp:
        fetch_cmd = [FETCH_ARTIFACT_BEYOND_CORP, '--use_oauth2',
                     '--bid', str(build_id), '--target', target, artifact_path, download_to]
    else:
        fetch_cmd = [FETCH_ARTIFACT,
                     '--bid', str(build_id), '--target', target, artifact_path, download_to]
    print("Running: " + ' '.join(fetch_cmd))
    try:
        subprocess.check_output(fetch_cmd, stderr=subprocess.STDOUT)
    except subprocess.CalledProcessError:
        print_e('FAIL: Unable to retrieve %s artifact for build ID %s' % (artifact_path, build_id))
        print_e('Please make sure you are authenticated for build server access!')
        return None
    return artifact_path


def fetch_artifacts(target, build_id, artifact_dict):
    for artifact, target_path in artifact_dict.items():
        artifact_path = fetch_artifact(target, build_id.url_id, artifact)
        if not artifact_path:
            return False
        mv(artifact_path, target_path)
    return True


def extract_artifact(artifact_path):
    # Unzip the repo archive into a separate directory.
    repo_dir = os.path.basename(artifact_path)[:-4]
    with zipfile.ZipFile(artifact_path) as zipFile:
        zipFile.extractall(repo_dir)
    return repo_dir


def fetch_and_extract(target, build_id, file, artifact_path=None):
    if not artifact_path:
        artifact_path = fetch_artifact(target, build_id, file)
    if not artifact_path:
        return None
    return extract_artifact(artifact_path)


def update_gmaven(gmaven_artifacts):
    artifacts = [GMavenArtifact(artifact) for artifact in gmaven_artifacts]
    for artifact in artifacts:
        if artifact.version == 'latest':
            artifact.version = artifact.get_latest_version()

    artifact_dirs = [fetch_gmaven_artifact(artifact) for artifact in artifacts]
    if not transform_maven_repos(['gmaven'], gmaven_dir, extract_res=False):
        return []
    return [artifact.key for artifact in artifacts]


def update_androidx(target, build_id, local_file):
    if build_id:
        repo_file = 'top-of-tree-m2repository-all-%s.zip' % build_id.fs_id
        repo_dir = fetch_and_extract(target, build_id.url_id, repo_file, None)
    else:
        repo_dir = fetch_and_extract(target, None, None, local_file)
    if not repo_dir:
        print_e('Failed to extract AndroidX repository')
        return False

    # Keep JavaPlugins.bp file untounched.
    java_plugins_bp_path = os.path.join(androidx_dir, 'JavaPlugins.bp')
    tmp_java_plugins_bp_path = os.path.join('/tmp', 'JavaPlugins.bp')
    mv(java_plugins_bp_path, tmp_java_plugins_bp_path)

    # Transform the repo archive into a Makefile-compatible format.
    if not transform_maven_repos([repo_dir], androidx_dir, extract_res=False):
        return False

    # Import JavaPlugins.bp in Android.bp.
    makefile = os.path.join(androidx_dir, 'Android.bp')
    with open(makefile, "a+") as f:
        f.write('\nbuild = ["JavaPlugins.bp"]\n')
    mv(tmp_java_plugins_bp_path, java_plugins_bp_path)

    return True


def update_jetifier(target, build_id):
    repo_file = 'jetifier-standalone.zip'
    repo_dir = fetch_and_extract(target, build_id.url_id, repo_file)
    if not repo_dir:
        print_e('Failed to extract Jetifier')
        return False

    rm(jetifier_dir)
    mv(os.path.join(repo_dir, 'jetifier-standalone'), jetifier_dir)
    os.chmod(os.path.join(jetifier_dir, 'bin', 'jetifier-standalone'), 0o755)
    return True


def update_constraint(local_file):
    repo_dir = extract_artifact(local_file)
    if not repo_dir:
        print_e('Failed to extract Constraint Layout')
        return False
    return transform_maven_repos([repo_dir], os.path.join(extras_dir, 'constraint-layout-x'), extract_res=False)


def update_material(file):
    design_dir = extract_artifact(file)
    if not design_dir:
        print_e('Failed to extract Material Design Components')
        return False

    # Don't bother extracting resources -- this should only be used with AAPT2.
    return transform_maven_repos([design_dir],
                                 os.path.join(extras_dir, 'material-design-x'), extract_res=False)


def update_framework(build_id, sdk_dir):
    api_scope_list = ['public', 'system', 'test', 'module-lib', 'system-server']
    if sdk_dir == 'current':
        api_scope_list.append('core')

    for api_scope in api_scope_list:
        target_dir = path(sdk_dir, api_scope)
        if api_scope == 'core':
            artifact_to_path = {'core.current.stubs.jar': path(target_dir, 'android.jar')}
        else:
            artifact_to_path = {'apistubs/android/' + api_scope + '/*.jar': path(target_dir, '*')}

        if not fetch_artifacts(framework_sdk_target, build_id, artifact_to_path):
            return False

        if api_scope == 'public':
            # Fetch a few artifacts from the public sdk.
            artifact = 'sdk-repo-linux-platforms-%s.zip' % build_id.fs_id
            artifact_path = fetch_artifact(framework_sdk_target, build_id.url_id, artifact)
            if not artifact_path:
                return False

            with zipfile.ZipFile(artifact_path) as zipFile:
                extra_files = [
                    'android.jar',
                    'framework.aidl',
                    'uiautomator.jar',
                    'core-for-system-modules.jar',
                    'data/annotations.zip',
                    'data/api-versions.xml']
                for filename in extra_files:
                    matches = list(filter(lambda path: filename in path, zipFile.namelist()))
                    if len(matches) != 1:
                        print_e('Expected 1 file named \'%s\' in zip %s, found %d' %
                                (filename, zipFile.filename, len(matches)))
                        return False
                    zip_path = matches[0]
                    src_path = zipFile.extract(zip_path)
                    dst_path = path(target_dir, filename)
                    mv(src_path, dst_path)

            # Filtered API DB is currently only available for "public"
            fetch_artifacts(framework_sdk_target, build_id, {'api-versions-public-filtered.xml': path(target_dir, 'data/api-versions-filtered.xml')})

    return True

def update_makefile(build_id):
    template = '"%s",\n\
        "current"'
    makefile = os.path.join(git_dir, 'Android.bp')

    with open(makefile, 'r+') as f:
        contents = f.read().replace('"current"', template % build_id)
        f.seek(0)
        f.write(contents)

    return True

def finalize_sdk(build_id, sdk_version):
    target_finalize_dir = '%d' % sdk_version

    for api_scope in ['public', 'system', 'test', 'module-lib', 'system-server']:
        artifact_to_path = {'apistubs/android/' + api_scope + '/api/*.txt':
                            path(target_finalize_dir, api_scope, 'api', '*')}

        if not fetch_artifacts(framework_sdk_target, build_id, artifact_to_path):
            return False

    return update_framework(build_id, target_finalize_dir) \
            and update_makefile(target_finalize_dir)


def update_framework_current(build_id):
    return update_framework(build_id, current_path)


def update_buildtools(target, arch, build_id):
    artifact_path = fetch_and_extract(target, build_id.url_id,
                                   "sdk-repo-%s-build-tools-%s.zip" % (arch, build_id.fs_id))
    if not artifact_path:
        return False

    top_level_dir = os.listdir(artifact_path)[0]
    src_path = os.path.join(artifact_path, top_level_dir)
    dst_path = path(buildtools_dir, arch)

    # There are a few libraries that have been manually added to the
    # build tools, copy them from the destination back to the source
    # before the destination is overwritten.
    files_to_save = (
        'lib64/libconscrypt_openjdk_jni.dylib',
        'lib64/libconscrypt_openjdk_jni.so',
        'bin/lib64/libwinpthread-1.dll',
    )
    for file in files_to_save:
        src_file = os.path.join(dst_path, file)
        dst_file = os.path.join(src_path, file)
        if os.path.exists(dst_path):
            mv(src_file, dst_file)

    mv(src_path, dst_path)

    # Move all top-level files to /bin and make them executable
    bin_path = path(dst_path, 'bin')
    top_level_files = filter(lambda e: os.path.isfile(path(dst_path, e)), os.listdir(dst_path))
    for file in top_level_files:
        src_file = path(dst_path, file)
        dst_file = path(bin_path, file)
        mv(src_file, dst_file)
        os.chmod(dst_file, 0o755)

    # Make the files under lld-bin executable
    lld_bin_files = os.listdir(os.path.join(dst_path, 'lld-bin'))
    for file in lld_bin_files:
        os.chmod(os.path.join(dst_path, 'lld-bin', file), 0o755)

    # Remove renderscript
    rm(path(dst_path, 'renderscript'))

    return True


def append(text, more_text):
    if text:
        return "%s, %s" % (text, more_text)
    return more_text


class buildId(object):
  def __init__(self, url_id, fs_id):
    # id when used in build server urls
    self.url_id = url_id
    # id when used in build commands
    self.fs_id = fs_id

def getBuildId(args):
  # must be in the format 12345 or P12345
  source = args.source
  number_text = source[:]
  presubmit = False
  if number_text.startswith("P"):
    presubmit = True
    number_text = number_text[1:]
  if not number_text.isnumeric():
    return None
  url_id = source
  fs_id = url_id
  if presubmit:
    fs_id = "0"
  args.file = False
  return buildId(url_id, fs_id)

def getFile(args):
  source = args.source
  if not source.isnumeric():
    return args.source
  return None


def script_relative(rel_path):
    return os.path.join(script_dir, rel_path)


def uncommittedChangesExist():
    try:
        # Make sure we don't overwrite any pending changes.
        diffCommand = "cd " + git_dir + " && git diff --quiet"
        subprocess.check_call(diffCommand, shell=True)
        subprocess.check_call(diffCommand + " --cached", shell=True)
        return False
    except subprocess.CalledProcessError:
        return True


rm(temp_dir)
parser = argparse.ArgumentParser(
    description=('Update current prebuilts'))
parser.add_argument(
    'source', nargs='?',
    help='Build server build ID or local Maven ZIP file')
parser.add_argument(
    '-m', '--material', action="store_true",
    help='If specified, updates only Material Design Components')
parser.add_argument(
    '-c', '--constraint', action="store_true",
    help='If specified, updates only Constraint Layout')
parser.add_argument(
    '-j', '--jetifier', action="store_true",
    help='If specified, updates only Jetifier')
parser.add_argument(
    '-p', '--platform', action="store_true",
    help='If specified, updates only the Android Platform')
parser.add_argument(
    '-f', '--finalize_sdk', type=int,
    help='If specified, imports the source build as the specified finalized SDK version')
parser.add_argument(
    '-b', '--buildtools', action="store_true",
    help='If specified, updates only the Build Tools')
parser.add_argument(
    '-x', '--androidx', action="store_true",
    help='If specified, updates only the Jetpack (androidx) libraries excluding those covered by other arguments')
parser.add_argument(
    '-g', '--gmaven', action="store_true",
    help='If specified, updates only the artifact from GMaven libraries excluding those covered by other arguments')
parser.add_argument(
    '--commit-first', action="store_true",
    help='If specified, then if uncommited changes exist, commit before continuing')
parser.add_argument(
    '--beyond-corp', action="store_true",
    help='If specified, then fetch artifacts with tooling that works on BeyondCorp devices')
args = parser.parse_args()
args.file = True
if not args.source and (args.platform or args.buildtools \
                or args.jetifier or args.androidx or args.material \
                or args.finalize_sdk or args.constraint):
    parser.error("You must specify a build ID or local Maven ZIP file")
    sys.exit(1)
if not (args.gmaven or args.platform or args.buildtools \
                or args.jetifier or args.androidx or args.material \
                or args.finalize_sdk or args.constraint):
    parser.error("You must specify at least one target to update")
    sys.exit(1)
if (args.constraint or args.material or args.androidx or args.gmaven) \
        and which('pom2bp') is None:
    parser.error("Cannot find pom2bp in path; please run lunch to set up build environment. You may also need to run 'm pom2bp' if it hasn't been built already.")
    sys.exit(1)

if uncommittedChangesExist():
    if args.commit_first:
        subprocess.check_call("cd " + git_dir + " && git add -u", shell=True)
        subprocess.check_call("cd " + git_dir + " && git commit -m 'save working state'", shell=True)

if uncommittedChangesExist():
    print_e('FAIL: There are uncommitted changes here. Please commit or stash before continuing, because %s will run "git reset --hard" if execution fails' % os.path.basename(__file__))
    sys.exit(1)

try:
    components = None
    if args.constraint:
        if update_constraint_x(getFile(args)):
            components = append(components, 'Constraint Layout X')
        else:
            print_e('Failed to update Constraint Layout X, aborting...')
            sys.exit(1)
    if args.gmaven:
        updated_artifacts = update_gmaven(gmaven_artifacts)
        if updated_artifacts:
            components = append(components, '\n'.join(updated_artifacts))
        else:
            print_e('Failed to update GMaven, aborting...')
            sys.exit(1)
    if args.androidx:
        if update_androidx('androidx', \
                           getBuildId(args), getFile(args)):
            components = append(components, 'AndroidX')
        else:
            print_e('Failed to update AndroidX, aborting...')
            sys.exit(1)
    if args.jetifier:
        if update_jetifier('androidx', getBuildId(args)):
            components = append(components, 'Jetifier')
        else:
            print_e('Failed to update Jetifier, aborting...')
            sys.exit(1)
    if args.platform or args.finalize_sdk:
        if update_framework_current(getBuildId(args)):
            components = append(components, 'platform SDK')
        else:
            print_e('Failed to update platform SDK, aborting...')
            sys.exit(1)
    if args.finalize_sdk:
        n = args.finalize_sdk
        if finalize_sdk(getBuildId(args), n):
            # We commit the finalized dir separately from the current sdk update.
            msg = "Import final sdk version %d from build %s" % (n, getBuildId(args).url_id)
            subprocess.check_call(['git', 'add', '%d' % n])
            subprocess.check_call(['git', 'add', 'Android.bp'])
            subprocess.check_call(['git', 'commit', '-m', msg])
        else:
            print_e('Failed to finalize SDK %d, aborting...' % n)
            sys.exit(1)
    if args.material:
        if update_material(getFile(args)):
            components = append(components, 'intermediate-AndroidX Design Library')
        else:
            print_e('Failed to update intermediate-AndroidX Design Library, aborting...')
            sys.exit(1)
    if args.buildtools:
        if update_buildtools('sdk_phone_armv7-sdk_mac', 'darwin', getBuildId(args)) \
                and update_buildtools('sdk_phone_x86_64-sdk', 'linux', getBuildId(args)) \
                and update_buildtools('sdk_phone_armv7-win_sdk', 'windows', getBuildId(args)):
            components = append(components, 'build tools')
        else:
            print_e('Failed to update build tools, aborting...')
            sys.exit(1)



    subprocess.check_call(['git', 'add', current_path, buildtools_dir])
    if not args.source and args.gmaven:
        src_msg = "GMaven"
    elif not args.source.isnumeric():
        src_msg = "local Maven ZIP"
    else:
        src_msg = "build %s" % (getBuildId(args).url_id)
    msg = "Import %s from %s\n\n%s" % (components, src_msg, flatten(sys.argv))
    subprocess.check_call(['git', 'commit', '-m', msg])
    if args.finalize_sdk:
        print('NOTE: Created two commits:')
        subprocess.check_call(['git', 'log', '-2', '--oneline'])
    print('Remember to test this change before uploading it to Gerrit!')

finally:
    # Revert all stray files, including the downloaded zip.
    try:
        with open(os.devnull, 'w') as bitbucket:
            subprocess.check_call(['git', 'add', '-Af', '.'], stdout=bitbucket)
            subprocess.check_call(
                ['git', 'commit', '-m', 'COMMIT TO REVERT - RESET ME!!!', '--allow-empty'], stdout=bitbucket)
            subprocess.check_call(['git', 'reset', '--hard', 'HEAD~1'], stdout=bitbucket)
    except subprocess.CalledProcessError:
        print_e('ERROR: Failed cleaning up, manual cleanup required!!!')
