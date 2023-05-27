import javax.swing.*;

public class GameMap extends JFrame {
    static int width = 800;
    static int height = 800;

    public GameMap(String name) {
        super(name);
        this.setSize(width, height);
        this.setVisible(true);
    }
}
