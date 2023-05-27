import javax.swing.*;
import java.awt.*;

public class Bombs {
    private int width;
    private int height;

    private int x;
    private int y;

    ImageIcon imageIcon = new ImageIcon("Images/Bombs.png");

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

    public void paint(Graphics graphics) {
        graphics.drawImage(imageIcon.getImage(), x, y, null);
    }
}
