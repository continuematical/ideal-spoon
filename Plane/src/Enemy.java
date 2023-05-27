import javax.swing.*;
import java.awt.*;
import java.util.Random;

public class Enemy {
    private int width;
    private int height;

    ImageIcon imageIcon = new ImageIcon("Images/enemy.png");

    private int x;
    private int y;

    public Enemy() {
        width = imageIcon.getIconWidth();
        height = imageIcon.getIconHeight();

        //设置敌机的位置
        Random random = new Random();
        random.nextInt(10);

        this.x = random.nextInt(GameMap.width - width / 2);
        this.y = -random.nextInt(GameMap.height - height / 2);
    }

    public int getWidth() {
        return width;
    }

    public void setWidth(int width) {
        this.width = width;
    }

    public int getHeight() {
        return height;
    }

    public void setHeight(int height) {
        this.height = height;
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    public void paintEnemy(Graphics graphics) {
        graphics.drawImage(imageIcon.getImage(), x, y, null);
    }

    public void move() {
        this.y += 1;
    }
}
