#!/bin/bash

SCREEN=$RANDOM

Xvfb :$SCREEN -nolisten tcp -screen :$SCREEN 1024x768x24 &

xvfb="$!"

DISPLAY=:$SCREEN arduino $@

kill -9 $xvfb