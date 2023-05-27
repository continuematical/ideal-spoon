import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferedImage;

public class PixelBlockDrawing extends JPanel {
    public static BufferedImage image;
    public static boolean[][] status = new boolean[Data.WIDTH / Data.SIZE + 2][Data.HEIGHT / Data.SIZE + 2];

    public PixelBlockDrawing(BufferedImage image2) {
        // 创建一个 BufferedImage 对象，宽度为 400 像素，高度为 400 像素，使用 RGB 颜色模式
        image = image2;
        // 将图像填充为白色
        Graphics g = image.getGraphics();
        g.setColor(Color.BLACK);
        g.fillRect(0, 0, Data.WIDTH, Data.HEIGHT);
        // 绘制像素块
        for (int i = 0; i < Data.WIDTH / Data.SIZE + 1; i++) {
            for (int j = 0; j < Data.HEIGHT / Data.SIZE + 1; j++) {
                if (!status[i][j])
                    drawPixelBlock(i * Data.SIZE, j * Data.SIZE, Data.SIZE, Data.SIZE, Color.BLACK, Color.WHITE);
                else drawPixelBlock(i * Data.SIZE, j * Data.SIZE, Data.SIZE, Data.SIZE, Color.WHITE, Color.WHITE);
            }
        }
    }

    public static void drawPixelBlock(int x, int y, int width, int height, Color fillColor, Color borderColor) {
        // 绘制边框矩形
        Graphics g = image.getGraphics();
        g.setColor(borderColor);
        g.drawRect(x, y, width, height);

        // 填充像素块内部
        g.setColor(fillColor);
        g.fillRect(x + 1, y + 1, width, height);
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        // 将绘制的图像绘制到面板上
        g.drawImage(image, 0, 0, null);
    }

    public static int NumAround(int x, int y) {
        int num = 0;
        for (int i = x - 1; i <= x + 1; i++) {
            for (int j = y - 1; j <= y + 1; j++) {
                if (status[i][j] && !(i == x && j == y))
                    num++;
            }
        }
        return num;
    }
}