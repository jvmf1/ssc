#!/usr/bin/python3

import numpy as np
import cv2
import sys
import math
import argparse

parser = argparse.ArgumentParser()
parser.add_argument("--rgb", action='store_true')
args = parser.parse_args()

orig_arr = bytearray(sys.stdin.buffer.read())


if args.rgb:

    size = math.sqrt(len(orig_arr)/3)

    dim = (math.ceil(size),math.ceil((len(orig_arr)/3)/math.ceil(size)),3)

else:

    size = math.sqrt(len(orig_arr))

    dim = (math.ceil(size), math.ceil(len(orig_arr)/math.ceil(size)))

if np.prod(dim) > len(orig_arr) != 0:

    arr = np.append(orig_arr, np.zeros(np.prod(dim) - len(orig_arr)))

else:

    arr = orig_arr

arr = np.array(arr).reshape(dim).astype(np.uint8)

print(arr.shape)

if np.prod(arr.shape) != len(orig_arr):
    print(f"Padding {np.prod(arr.shape)-len(orig_arr)} bytes")

cv2.namedWindow("a", cv2.WINDOW_KEEPRATIO)
cv2.imshow("a", arr)

key = cv2.waitKey(0) & 0xFF
