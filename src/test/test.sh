#!/bin/bash

output_files=()

if [ $# -eq 0 ]; then
    set -- test-suites/BFP.xml test-suites/irioCoreUnit.xml test-suites/irioCoreCppUnit.xml
fi

case "$1" in
--help|-h)
    echo "Run the given test(s) on XML format and check if they pass"
    echo "Usage: $0 <TEST1> [TEST2] ..."
    exit 0
    ;;
esac

mkdir -p test-results
for executable in "$@"; do
    ./automate_GT.py -i $executable -o test-results/$(basename $executable .xml).xml -S
    if [ $? -ne 0 ]; then
        echo "$executable failed"
        exit 1
    fi
    output_files+=("test-results/$(basename $executable .xml).xml")
done

for f in $output_files; do
    if grep -q "<summary>FAIL</summary>" $f; then
        exit 1
    fi
done