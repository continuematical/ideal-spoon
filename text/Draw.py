import cv2
import numpy as np


def cv_show(name, img):
    cv2.imshow(name, img)
    # 无限时间的显示函数
    key = cv2.waitKey(0)
    if key == 27:
        # 按下任意键可以关闭窗口
        cv2.destroyAllWindows()
    elif key == ord('s'):
        cv2.imwrite('messieurs.png', img)
        cv2.destroyAllWindows()


# opencv
def demo1():
    img = cv2.imread("img1.png")
    cv_show("img", img)

    # matplotlib
    # plt.imshow(img, cmap='gray', interpolation='bicubic')
    # plt.xticks([])
    # plt.yticks([])
    # plt.show()


# 鼠标事件 坐标 组合按键
def mouse_callback(event, x, y, flags, userData):
    print(event, x, y, flags, userData)


img_black = np.zeros((512, 512, 3), np.uint8)


def draw_circle(event, x, y, flags, param):
    global ix, iy, drawing, mode
    if event == cv2.EVENT_LBUTTONDOWN:
        drawing = True
    elif event == cv2.EVENT_MOUSEMOVE:
        if drawing == True:
            if mode == True:
                cv2.rectangle(img_black, (ix, iy), (x, y), (0, 255, 0), -1)
            else:
                cv2.circle(img_black, (x, y), 5, (0, 0, 255), -1)
    elif event == cv2.EVENT_LBUTTONUP:
        drawing = False
        if mode == True:
            cv2.rectangle(img_black, (ix, iy), (x, y), (0, 255, 0), -1)
        else:
            cv2.circle(img_black, (x, y), 5, (0, 0, 255), -1)


def mouse_demo():
    # 创建窗口
    cv2.namedWindow('mouse', cv2.WINDOW_NORMAL)
    cv2.resizeWindow('mouse', 640, 360)

    # 设置鼠标的回调函数
    cv2.setMouseCallback('mouse', draw_circle, '123')
    # 生成全黑的图片
    img = np.zeros((360, 640), np.uint8)
    cv_show('mouse', img)


# 根据numpy的属性访问属性
def visit():
    # 访问图像
    img = cv2.imread('img1.png')
    # 高度 长度 通道数
    print(img.shape)
    # 图像占用空间
    print(img.size)
    # 每个元素的位深
    print(img.dtype)


def spilt():
    img = np.zeros((200, 200, 3), np.uint8)
    b, g, r = cv2.split(img)
    b[10:100, 10:100] = 255
    g[10:100, 10:100] = 255
    new_img = cv2.merge((b, g, r))
    cv_show('new_img', new_img)


def track_callback(value):
    print(value)


def track_demo():
    cv2.namedWindow('trackbar', cv2.WINDOW_NORMAL)
    cv2.resizeWindow('trackbar', 640, 360)
    # trackbar名称 窗口名称 起点 终点 回调函数
    cv2.createTrackbar('R', 'trackbar', 0, 255, track_callback)
    cv2.createTrackbar('G', 'trackbar', 0, 255, track_callback)
    cv2.createTrackbar('B', 'trackbar', 0, 255, track_callback)

    img = np.zeros((360, 640, 3), np.uint8)

    while True:
        # 获取当前trackbar的值
        b = cv2.getTrackbarPos('B', 'trackbar')
        g = cv2.getTrackbarPos('G', 'trackbar')
        r = cv2.getTrackbarPos('R', 'trackbar')
        # 展现背景图片
        img[:] = [b, g, r]
        cv_show('trackbar', img)


# 绘制直线
def draw_line():
    img = np.zeros((480, 640, 3), np.uint8)
    cv2.line(img, (0, 0), (200, 200), (0, 0, 255), 5, 4)
    cv2.line(img, (80, 100), (380, 480), (0, 0, 255), 5, 16)
    cv_show('line', img)


def draw_rectangle():
    img = np.zeros((480, 640, 3), np.uint8)
    cv2.rectangle(img, (0, 0), (200, 200), (0, 0, 255), 5, 4)
    cv_show('rectangle', img)


def draw_circle():
    img = np.zeros((480, 640, 3), np.uint8)
    cv2.circle(img, (447, 63), 63, (0, 0, 255), -1)
    cv_show('circle', img)


def draw_ellipse():
    img = np.zeros((480, 640, 3), np.uint8)
    # 图片 中心点 长轴 短轴
    cv2.ellipse(img, (256, 256), (100, 50), 0, 0, 180, 255)
    cv_show('ellipse', img)


def draw_poly():
    # 多边形的点集 必须是int32位以上
    pts = np.array([(10, 5), (20, 30), (70, 20), (50, 10)], np.int32)
    img = np.zeros((480, 640, 3), np.uint8)
    # 注意是点集的集合，所以pts是三维的
    cv2.polylines(img, [pts], True, (0, 0, 255))
    cv_show('poly', img)


def draw_text():
    img = np.zeros((480, 640, 3), np.uint8)
    cv2.putText(img, 'OpenCV', (100, 100), cv2.FONT_HERSHEY_COMPLEX, 5, [0, 0, 255])
    cv_show('text', img)


def draw_Chinese_text():
    # 无法绘制中文，可以使用pillow包
    img = np.full((500, 500, 3), fill_value=255, dtype=np.uint8)
    from PIL import ImageFont, ImageDraw, Image
    # 导入字体文件
    font = ImageFont.truetype('./STXINGKA.TTF', 35)
    # 创建一个pillow的图片
    img_pil = Image.fromarray(img)

    draw = ImageDraw.Draw(img_pil)
    # 利用draw绘制中文
    # fill指定颜色
    draw.text((10, 150), "你好", font=font, fill=(0, 255, 0, 0))

    # 重新变回ndarray
    img = np.array(img_pil)
    cv_show('Chinese_text', img)


# 图像的运算
def cal():
    img1 = cv2.imread('img1.png')
    img2 = cv2.imread('img2.png')
    img2 = img2[0:448, :504]
    # add的规则是两个对应的图片元素相加，如果超过255则全部变为255
    # cv_show('new_img', cv2.add(img1, img2))
    # 与整数相加
    # 相当于 % 256
    # img1 += 100
    # cv_show('new_img', img1)
    # 减法，对应元素相减，如果小于零，则直接变为零
    # 图片融合
    cv_show('new_img', cv2.addWeighted(img1, 0.6, img2, 0.4, 0))


# 图片的逻辑运算
def logic():
    # 非操作
    img = cv2.imread('img1.png')
    cv_show('not_img', cv2.bitwise_not(img))


# 图形的基本变换
def tran():
    # resize
    img = cv2.imread('img1.png')
    # cv_show('new_img', cv2.resize(img, (800, 400), interpolation=cv2.INTER_NEAREST))

    # 翻转
    # cv_show('new_img', cv2.flip(img, flipCode=0))

    # 旋转
    # cv_show('new_img', cv2.rotate(img, rotateCode=cv2.ROTATE_180))

    # 平移
    h, w, s = img.shape
    M = np.float32([[1, 0, 200], [0, 1, 0]])
    new_img = cv2.warpAffine(img, M, (w, h), flags=cv2.INTER_NEAREST)
    cv_show('new_img', new_img)


def rotate_getM():
    img = cv2.imread('img1.png')
    h, w, s = img.shape
    # M = cv2.getRotationMatrix2D((10, 10), 15, 1)
    # new_img = cv2.warpAffine(img, M, (w, h), flags=cv2.INTER_NEAREST)
    # cv_show('new_img', new_img)

    M = np.float32([[200, 100], [300, 100], [200, 300]])
    N = np.float32([[100, 150], [360, 200], [280, 120]])
    res = cv2.getAffineTransform(M, N)
    cv_show('new_img', cv2.warpAffine(img, res, (w, h), flags=cv2.INTER_NEAREST))
