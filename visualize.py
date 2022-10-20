#!/usr/bin/python3

import numpy as np
import cv2
import sys
import math

arr = bytearray(sys.stdin.buffer.read())

size = int(math.sqrt(len(arr)))

arr = np.array(arr).reshape((size,size)).astype(np.uint8)

cv2.namedWindow("a", cv2.WINDOW_KEEPRATIO)
cv2.imshow("a", arr)

key = cv2.waitKey(0) & 0xFF
