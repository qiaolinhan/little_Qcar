#!/usr/bin/env python3
# -*- coding: utf-8 -*- #

# ------------------------------------------------------------------------------
#
#   Copyright (C) 2022 Concordia NAVlab. All rights reserved.
#
#   @Filename: equations.py
#
#   @Author: Linhan Qiao
#
#   @Date: 2022-07-25
#
#   @Email: q_linhan@live.concordia.ca
#
#   @Description: 
#
# ------------------------------------------------------------------------------



# R_l, R_f: learder robot, follower robot
# F_o: the world reference system
# F_i: body-fixed frame (F_l, F_f)

# for the car model:
#------------------
# p_i = [x_i, y_i]^T: position of R_i, on F_o
# $\theta$: orientation of R_i, on F_o
# $v_i$, $\omega_i$: linear velocity, angular velocity of R_i

# kinetics of each robot can be described as:
# -------------------------------------------
# dot(x_i) = v_i * cos(theta_i)
# dot(y_i) = v_i * sin(theta_i)
# dot(theta_i) = omega_i

import numpy as np
from sympy import *
import sympy as sy
# positions
x_l, y_l, x_f, y_f = sy.symbols("x_l y_l x_f y_f")

# orientations
theta_f = sy.Symbol("theta_f")
# cos_theta_f, sin_theta_f = sy.symbols("cos_theta_f, sin_theta_f")

# for R_f
R_theta_f = sy.Matrix[[sy.cos(theta_f), sy.sin(theta_f)],
                      [-sy.sin(theta_f), sy.cos(theta_f)]]
# R_theta_f = [[cos_theta_f, sin_theta_f], [-sin_theta_f, cos_theta_f]]
# # for R_f and R_l
res_lf = sy.Matrix[[x_l - x_f], [y_l - y_f]]

# print params
print(f"======> Residual between R-l and R_f:\n {res_lf}")
print(f"======> The shape of res_lf: {res_lf.shape}\n")
print(f"======> Orientation on R_f frame:\n {R_theta_f} ")
print(f"======> The shape of R_theta_f: {R_theta_f.shape}\n")
# relationship between R_l and R_f
print(R_theta_f * res_lf)


