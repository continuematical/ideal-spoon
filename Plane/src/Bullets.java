import javax.swing.*;
import java.awt.*;

public class Bullets {
    private int width;
    private int height;

    private int x;
    private int y;

    ImageIcon imageIcon = new ImageIcon("Images/Bullets.png");

    public Bullets(int x, int y) {
        this.x = x;
        this.y = y;
        width = imageIcon.getIconWidth();
        height = imageIcon.getIconHeight();
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

    public ImageIcon getImageIcon() {
        return imageIcon;
    }

    public void setImageIcon(ImageIcon imageIcon) {
        this.imageIcon = imageIcon;
    }

    public void move() {
        this.y -= 4;
    }

    public void drawImage(Graphics graphics) {
        graphics.drawImage(imageIcon.getImage(), x, y, null);
    }
}
