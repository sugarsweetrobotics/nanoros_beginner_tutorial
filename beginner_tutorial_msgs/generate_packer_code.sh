#!/bin/bash

mkdir -p output
cd output

nanorosmsgparser ../../beginner_tutorial_msgs

cd beginner_tutorial_msgs
mkdir -p build
cd build
cmake ../;make
