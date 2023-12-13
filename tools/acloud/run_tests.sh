#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color
ACLOUD_DIR=$(dirname $(realpath $0))
TOOLS_DIR=$(dirname $ACLOUD_DIR)
THIRD_PARTY_DIR=$(dirname $TOOLS_DIR)/external/python

function get_python_path() {
    local python_path=$TOOLS_DIR
    local third_party_libs=(
        "apitools"
        "dateutil"
        "google-api-python-client"
        "oauth2client"
        "uritemplates"
        "rsa"
    )
    for lib in ${third_party_libs[*]};
    do
        python_path=$THIRD_PARTY_DIR/$lib:$python_path
    done
    python_path=$python_path:$PYTHONPATH
    echo $python_path
}

function print_summary() {
    local test_results=$1
    local tmp_dir=$(mktemp -d)
    local rc_file=${ACLOUD_DIR}/.coveragerc
    PYTHONPATH=$(get_python_path) python3 -m coverage report -m
    PYTHONPATH=$(get_python_path) python3 -m coverage html -d $tmp_dir --rcfile=$rc_file
    echo "coverage report available at file://${tmp_dir}/index.html"

    if [[ $test_results -eq 0 ]]; then
        echo -e "${GREEN}All unittests pass${NC}!"
    else
        echo -e "${RED}There was a unittest failure${NC}"
    fi
}

function run_unittests() {
    local specified_tests=$@
    local rc=0
    local run_cmd="python3 -m coverage run --append"

    # clear previously collected coverage data.
    PYTHONPATH=$(get_python_path) python3 -m coverage erase

    # Get all unit tests under tools/acloud.
    local all_tests=$(find $ACLOUD_DIR -type f -name "*_test.py" ! -name "acloud_test.py");
    local tests_to_run=$all_tests

    # Filter out the tests if specified.
    if [[ ! -z $specified_tests ]]; then
        tests_to_run=()
        for t in $all_tests;
        do
            for t_pattern in $specified_tests;
            do
                if [[ "$t" =~ "$t_pattern" ]]; then
                    tests_to_run=("${tests_to_run[@]}" "$t")
                fi
            done
        done
    fi

    for t in $tests_to_run;
    do
        if ! PYTHONPATH=$(get_python_path):$PYTHONPATH $run_cmd $t; then
            rc=1
            echo -e "${RED}$t failed${NC}"
        fi
    done

    print_summary $rc
    cleanup
    exit $rc
}

function check_env() {
    if [ -z "$ANDROID_HOST_OUT" ]; then
        echo "Missing ANDROID_HOST_OUT env variable. Run 'lunch' first."
        exit 1
    fi
    if [ ! -f "$ANDROID_HOST_OUT/bin/aprotoc" ]; then
        echo "Missing aprotoc. Run 'm aprotoc' first."
        exit 1
    fi

    local missing_py_packages=false
    for py_lib in {coverage,mock};
    do
        if ! python3 -m pip list | grep $py_lib &> /dev/null; then
            echo "Missing required python package: $py_lib (python3 -m pip install $py_lib)"
            missing_py_packages=true
        fi
    done
    if $missing_py_packages; then
        exit 1
    fi
}

function gen_proto_py() {
    # Use aprotoc to generate python proto files.
    local protoc_cmd=$ANDROID_HOST_OUT/bin/aprotoc
    pushd $ACLOUD_DIR &> /dev/null
    $protoc_cmd internal/proto/*.proto --python_out=./
    touch internal/proto/__init__.py
    popd &> /dev/null
}

function cleanup() {
    # Search for *.pyc and delete them.
    find $ACLOUD_DIR -name "*.pyc" -exec rm -f {} \;

    # Delete the generated proto files too.
    find $ACLOUD_DIR/internal/proto -name "*.py" -exec rm -f {} \;
}

check_env
cleanup
gen_proto_py
run_unittests $@
