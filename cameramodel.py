#!/usr/bin/env python3
# -*- coding: utf-8 -*- #

# ------------------------------------------------------------------------------
#
#   Copyright (C) 2022 Concordia NAVlab. All rights reserved.
#
#   @Filename: camera_model.py
#
#   @Author: Linhan Qiao
#
#   @Date: 2022-07-26
#
#   @Email: q_linhan@live.concordia.ca
#
#   @Description: camera is utilized in the leader-following system to
#                 obtian the information required to coordinate their motion.
#
# ------------------------------------------------------------------------------


# Assumption: a monocular camera mounted onboard the follower robot
#   The optical axis is aligned with the 'x-axis' of the frame F_f
#   Using common pinhole camera model
#   
# On camera frame, a 3D point: P = [X, Y, Z]^T
#     corresponding 2D point: u = [m, n]^T
# Define the normalized coordinate: s = [p, q]^T  
# The corresponding constrains imposed on the normalized coordinates:
#   p_min <= p <= p_max, q_min <= q <= q_max

# A visual feedback controller for the leader-following system 
# using only information from onboard camera images
# desired constant visual feature vector s^* = [p^*, q^*]^T
# the goal: to design a controller for R_f, without violatinf the visibility constraints.

# Assumption 1: velocity of leader cannot be measured, but it is bounded
# (The velocity of wildfire point cannot be measured, but is bounded)

# Assumption 2: The feature point 'P' is initially within the field-of-view of camera.
# (The centre of wildfire point is initially within the field-of-view of camera)

# 
