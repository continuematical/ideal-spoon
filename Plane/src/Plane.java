import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;
import java.util.ArrayList;

public class Plane extends JPanel implements MouseMotionListener {
    ImageIcon imageIcon = new ImageIcon("Images/hero.png");
    ArrayList<Bombs> bombs = new ArrayList<>();
    ArrayList<Bullets> bullets = new ArrayList<>();
    ArrayList<Enemy> enemies = new ArrayList<>();

    int heroX = 300;
    int heroY = 400;
    int number = 0;//得分

    public Plane() {
        for (int i = 0; i < 10; i++) {
            enemies.add(new Enemy());
        }
    }

    /**
     * 初始化
     */

    public void init() {
        int flag = 0;
        while (true) {
            flag++;
            if (flag % 10 == 0) {
                Bullets bullet = new Bullets(imageIcon.getIconWidth() / 2 + heroX, heroY);
                bullets.add(bullet);
            }

            for (int i = 0; i < enemies.size(); i++) {
                Enemy enemy = enemies.get(i);
                enemy.move();

                if (enemy.getY() > GameMap.width) {
                    enemies.remove(enemy);
                    enemies.add(new Enemy());
                }
            }

            //子弹
            for (int i = 0; i < bullets.size(); i++) {
                Bullets tempBullet = bullets.get(i);
                tempBullet.move();
            }

            for (int i = 0; i < bullets.size(); i++) {
                Bullets tempBullet = bullets.get(i);
                if (tempBullet.getY() < 0) {
                    bullets.remove(tempBullet);
                }
            }
        }
    }

    @Override
    public void mouseDragged(MouseEvent e) {
        int x = e.getX();
        int y = e.getY();

        heroX = x - imageIcon.getIconWidth() / 2;
        heroY = y - imageIcon.getIconHeight() / 2;

        if (x + imageIcon.getIconWidth() > GameMap.width) {
            heroX = GameMap.width - imageIcon.getIconWidth() - 20;
        }
        if (y + imageIcon.getIconHeight() > GameMap.height) {
            heroY = GameMap.height - imageIcon.getIconHeight() - 20;
        }
    }

    @Override
    public void mouseMoved(MouseEvent e) {
        int x = e.getX();
        int y = e.getY();

        heroX = x - imageIcon.getIconWidth() / 2;
        heroY = y - imageIcon.getIconHeight() / 2;

        if (x + imageIcon.getIconWidth() > GameMap.width) {
            heroX = GameMap.width - imageIcon.getIconWidth() - 20;
        }
        if (y + imageIcon.getIconHeight() > GameMap.height) {
            heroY = GameMap.height - imageIcon.getIconHeight() - 20;
        }
    }

    @Override
    public void paint(Graphics g) {
        super.paint(g);

        g.setFont(new Font("", Color.RED.getRed(), 30));
        g.drawString("得分" + number, 20, 30);

        g.drawImage(imageIcon.getImage(), heroX, heroY, null);

        //绘制敌人
        for (int i = 0; i < enemies.size(); i++) {
            enemies.get(i).paintEnemy(g);
        }

        //绘制子弹
        for (int i = 0; i < bullets.size(); i++) {
            bullets.get(i).drawImage(g);
        }

        //绘制爆炸图片
        for (int i = 0; i < bombs.size(); i++) {
            bombs.get(i).paint(g);
        }
    }
}
