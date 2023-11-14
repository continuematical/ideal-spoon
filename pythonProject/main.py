import pandas as pd
import matplotlib.pyplot as plt


# 选择各个品类的商品信息
def select(path, name):
    information = pd.read_excel(path)
    res = pd.DataFrame()
    for i in range(1, 250):
        if information.loc[i, '分类名称'] == name:
            res.loc[i, '单品名称'] = information.loc[i, '单品名称']
            res.loc[i, '单品编码'] = information.loc[i, '单品编码']
    return res


# 获取某一列的单品种类
def get_species(data, name):
    species = []
    species.append(data.loc[1, name])
    for i in range(2, len(data.index)):
        if data.loc[i, name] != data.loc[i - 1, '单品名称']:
            species.append(data.loc[i, '单品名称'])
    return species


# 得到各品类各商品的销售额
def sales(path, name, year, num):
    sale = pd.read_excel(year + "第" + num + "季度销售量.xlsx")
    data = select(path, name)
    merge_data = pd.merge(data, sale, how='inner', on='单品编码')
    merge_data.to_excel(name + "第" + num + "各品类销售量.xlsx")


# 绘制各个商品丰富度的饼状图
def picture_richness():
    from pylab import mpl
    # 设置显示中文字体
    mpl.rcParams["font.sans-serif"] = ["SimHei"]
    data = pd.read_excel("附件1.xlsx")
    variety = pd.DataFrame({'花叶类': [0], '花菜类': [0], '水生根茎类': [0], '茄类': [0], '辣椒类': [0], '食用菌': [0]})
    for i in range(1, 250):
        variety.loc[0, data.loc[i, '分类名称']] += 1
    # 绘制饼状图
    plt.figure()
    plt.pie(x=variety.loc[0, :], autopct="%.2f%%")
    plt.legend(variety.columns, loc="best")
    plt.show()


sales("附件1.xlsx", '花叶类', '2020', '3')