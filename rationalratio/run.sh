#!/bin/bash

for f in `seq -w 1 36`
do
  python3 rationalratio.py < "$f.in" | diff - "$f.ans"
done
