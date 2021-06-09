# import numpy as np
import collections
import cv2


# 定义HSV颜色字典，参考网上HSV颜色分类
def get_color_list0():
    dict0 = collections.defaultdict()
    # 白色
    lower_white = [0, 0, 46]
    upper_white = [180, 40, 255]
    color_list = [lower_white, upper_white]
    dict0["white"] = color_list
    # 红色
    lower_red = [0, 43, 46]
    upper_red = [5, 255, 255]
    color_list = [lower_red, upper_red]
    dict0["red"] = color_list
    # 红色2
    lower_orange = [175, 43, 46]
    upper_orange = [180, 255, 255]
    color_list = [lower_orange, upper_orange]
    dict0["orange2"] = color_list
    # 橙色
    lower_orange = [9, 43, 46]
    upper_orange = [25, 255, 255]
    color_list = [lower_orange, upper_orange]
    dict0["orange"] = color_list
    # 黄色
    lower_yellow = [25, 43, 46]
    upper_yellow = [45, 255, 255]
    color_list = [lower_yellow, upper_yellow]
    dict0["yellow"] = color_list
    # 绿色
    lower_green = [46, 43, 46]
    upper_green = [77, 255, 255]
    color_list = [lower_green, upper_green]
    dict0["green"] = color_list
    # 蓝色
    lower_blue = [78, 43, 46]
    upper_blue = [100, 255, 255]
    color_list = [lower_blue, upper_blue]
    dict0["blue"] = color_list
    return dict0


def get_color_list():
    # 6/6
    dict0 = collections.defaultdict()
    # 定义字典存放颜色分量上下限
    # 例如：{颜色: [min分量, max分量]}

    # 白色
    # lower_white = [0, 0, 221]
    lower_white = [0, 0, 46]
    upper_white = [180, 46, 255]
    color_list = [lower_white, upper_white]
    dict0["white"] = color_list
    # 红色
    lower_red = [156, 52, 46]
    upper_red = [180, 255, 255]
    color_list = [lower_red, upper_red]
    dict0["red"] = color_list
    # 红色2
    # lower_red = [0, 52, 46]
    # upper_red = [3, 255, 255]
    # color_list = [lower_red, upper_red]
    # dict0["red2"] = color_list
    # 橙色
    lower_orange = [1, 52, 46]
    upper_orange = [10, 255, 255]
    color_list = [lower_orange, upper_orange]
    dict0["orange"] = color_list
    # 黄色
    lower_yellow = [11, 52, 46]
    upper_yellow = [50, 255, 255]
    color_list = [lower_yellow, upper_yellow]
    dict0["yellow"] = color_list
    # 绿色
    lower_green = [51, 52, 46]
    upper_green = [87, 255, 255]
    color_list = [lower_green, upper_green]
    dict0["green"] = color_list
    # 蓝色
    lower_blue = [105, 52, 120]
    upper_blue = [120, 255, 255]
    color_list = [lower_blue, upper_blue]
    dict0["blue"] = color_list

    return dict0


def rgb2hsv(r, g, b):
    r, g, b = r / 255.0, g / 255.0, b / 255.0
    mx = max(r, g, b)
    mn = min(r, g, b)
    v = mx

    m = mx - mn
    if mx == 0:
        s = 0
    else:
        s = m / mx

    if mx == mn:
        h_local = 0
    elif mx == r:
        if g >= b:
            h_local = ((g - b) / m) * 60
        else:
            h_local = ((g - b) / m) * 60 + 360
    elif mx == g:
        h_local = ((b - r) / m) * 60 + 120
    elif mx == b:
        h_local = ((r - g) / m) * 60 + 240

    H = h_local / 2
    S = s * 255.0
    V = v * 255.0

    HSV = [H, S, V]
    return HSV


def get_color0(center, img):  # 返回颜色列表
    # 先看一共识别出多少个元素/色块
    num = len(center)

    # 调用颜色表
    color_0 = []
    color_dict = get_color_list0()  # {颜色: [min分量, max分量]}
    index = 0
    # 将每一个色块对比
    for ia in range(num):
        cx = center[ia][0]
        cy = center[ia][1]
        data = img[cy, cx]
        data2 = rgb2hsv(data[2], data[1], data[0])

        # 遍历颜色表与 data 进行对比
        for k_color in color_dict:
            color_low = color_dict[k_color][0]  # 下限
            color_high = color_dict[k_color][1]  # 上限
            k = 0
            for j in range(3):
                if (data2[j] >= color_low[j]) & (data2[j] <= color_high[j]):
                    k += 1
                else:
                    break

            if k == 3:
                dict1 = {"index": index, "cx": cx, "cy": cy, "color": k_color}
                color_0.append(dict1)
                index += 1
            else:
                continue

    return color_0


def get_color(center, img):
    # center 是列表， img是cv2.imread读入的裁剪过的图像（原来的彩色图像）
    num = len(center)

    # 调用颜色表
    color_0 = []
    color_dict = get_color_list()  # {颜色: [min分量, max分量]}
    color2num = {"white": 1, "blue": 2, "red": 3, "red2": 3, "orange": 4, "green": 5, "yellow": 6}
    index = 0
    # 将每一个色块对比
    for ii in range(num):
        cx = center[ii][0]
        cy = center[ii][1]
        data = img[cy, cx]  # 读入的img是BGR型
        data2 = rgb2hsv(data[2], data[1], data[0])

        # 遍历颜色表与 data 进行对比
        for k_color in color_dict:
            color_low = color_dict[k_color][0]  # 下限
            color_high = color_dict[k_color][1]  # 上限
            k = 0
            for j in range(3):
                if (data2[j] >= color_low[j]) & (data2[j] <= color_high[j]):
                    k += 1
                else:
                    break

            if k == 3:
                dict1 = {"index": index, "cx": cx, "cy": cy, "color": k_color, "number": color2num[k_color]}
                color_0.append(dict1)
                index += 1
                break
            else:
                continue

    return color_0


center11 = [[66, 43], [63, 87], [62, 135], [62, 193], [64, 243], [66, 286], [142, 133], [141, 183],
            [208, 42], [208, 82], [217, 127], [219, 183], [213, 237], [205, 288]]
# center12 = [[127, 91], [121, 218], [112, 362], [114, 495], [129, 606], [154, 699], [311, 392], [312, 514],
#             [483, 85], [497, 229], [510, 386], [510, 514], [500, 609], [500, 689]]
center12 = [[51, 39], [54, 94], [47, 156], [49, 216], [57, 265], [68, 308], [137, 167], [136, 228],
            [209, 38], [220, 99], [218, 165], [221, 225], [222, 264], [217, 296]]
center13 = [[218, 86], [205, 173], [201, 270], [197, 403], [200, 535], [217, 656], [381, 288], [376, 417],
            [536, 84], [545, 178], [557, 286], [559, 423], [549, 551], [541, 656]]  # 6/7-version


image = cv2.imread(r'D:\mofang\pic_1.jpg')
color = []

height, width = image.shape[:2]
image = image[int(0 * height):int(1 * height), int(0.2 * width):int(0.72 * width)]
height, width = image.shape[:2]
size = (int(width * 0.7), int(height * 0.7))
image = cv2.resize(image, size, interpolation=cv2.INTER_AREA)
cv2.imshow("img", image)
cv2.waitKey(0)

color = get_color(center13, image)
print("result of img")
print(len(color))
for i in range(len(color)):
    print(color[i])
