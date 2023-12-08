import matplotlib.pyplot as plt
import numpy as np
from scipy.integrate import odeint


# 定义系统动力学方程
def system_dynamics(y, t, r, ef_ic, ef_ev):
    ev, co2, aqi = y

    dev_dt = r * ev  # 电动车增长率
    dco2_dt = ef_ic - ef_ev * ev  # 减少的碳排放
    daqi_dt = -dco2_dt / 1000  # 假设AQI与CO2负相关
    return [dev_dt, dco2_dt, daqi_dt]


def text():
    # 初始条件
    y0 = [1000, 5000, 100]  # 初始电动车数量,初始CO2排放量,初始AQI
    # 时间点
    t = np.linspace(0, 10, 200)  # 10年
    # 参数
    r = 0.1  # 电动车增长率
    ef_ic = 3000  # 传统车辆的碳排放系数
    ef_ev = 1000  # 电动车辆的碳排放系数
    # 求解微分方程
    solution = odeint(system_dynamics, y0, t, args=(r, ef_ic, ef_ev))
    # 可视化
    plt.figure(figsize=(12, 6))
    plt.plot(t, solution[:, 0], label='Electric Vehicles (EV)')
    # plt.plot(t, solution[:, 1], label='C02 Emissions Reduction')
    # plt.plot(t, solution[:, 2], label='Air Quality Index(AQI)')
    plt.xlabel('Time (Years)')
    plt.ylabel('Value')
    plt.title('System Dynamics Model of EV Impact on Environment')
    plt.legend()
    plt.show()
