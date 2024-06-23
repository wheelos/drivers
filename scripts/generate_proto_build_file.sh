#!/bin/bash

for directory in common_msgs/*; do
    if [ -d "$directory" ]; then
        python3 scripts/proto_build_generator.py "$directory/BUILD"
    fi
done
