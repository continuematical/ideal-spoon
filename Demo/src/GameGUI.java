import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class GameGUI extends JFrame implements ActionListener {

    public static BufferedImage image;

    public static long seed = 1234;
    public static int flag = 0;

    private JMenuItem start;
    private JMenuItem stop;
    private JMenuItem random;
    private JMenuItem remove;
    private Thread thread;
    ArrayList<List<Cell>> cells = new ArrayList<>();

    public GameGUI(String name) {
        super(name);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
        this.setSize(Data.WIDTH + Data.WIDTH / Data.SIZE, Data.HEIGHT + Data.HEIGHT / Data.SIZE);

        for (int i = 0; i < Data.WIDTH / Data.SIZE; i++) {
            cells.add(new ArrayList<>());
            for (int j = 0; j < Data.HEIGHT / Data.SIZE; j++) {
                cells.get(i).add(new Cell(false));
            }
        }
        initComponent(this);
    }

    public void random() {
        Random random = new Random(seed);
        for (int i = 0; i < ((Data.WIDTH / Data.SIZE) * (Data.HEIGHT / Data.SIZE)) / 2; i++) {
            int x = random.nextInt(0, Data.WIDTH / Data.SIZE);
            int y = random.nextInt(0, Data.HEIGHT / Data.SIZE);
            cells.get(x).get(y).setNextStatus(true);
        }
        for (int i = 0; i < Data.WIDTH / Data.SIZE + 2; i++) {
            for (int j = 0; j < Data.HEIGHT / Data.SIZE + 2; j++) {
                PixelBlockDrawing.status[i][j] = false;
            }
        }
        start();
    }

    public void start() {
        thread = new Thread(() -> {
            for (; ; ) {
                if (flag == 1) break;
                for (int i = 0; i < Data.WIDTH / Data.SIZE; i++) {
                    for (int j = 0; j < Data.HEIGHT / Data.SIZE; j++) {
                        cells.get(i).get(j).Status = cells.get(i).get(j).nextStatus;
                    }
                }
                for (int i = 0; i < Data.WIDTH / Data.SIZE; i++) {
                    for (int j = 0; j < Data.HEIGHT / Data.SIZE; j++) {
                        PixelBlockDrawing.status[i + 1][j + 1] = cells.get(i).get(j).Status;
                    }
                }
                for (int i = 0; i < Data.WIDTH / Data.SIZE; i++) {
                    for (int j = 0; j < Data.HEIGHT / Data.SIZE; j++) {
                        cells.get(i).get(j).LivingNum = PixelBlockDrawing.NumAround(i + 1, j + 1);
                    }
                }
                for (int i = 0; i < Data.WIDTH / Data.SIZE; i++) {
                    for (int j = 0; j < Data.HEIGHT / Data.SIZE; j++) {
                        cells.get(i).get(j).setNextStatus();
                    }
                }
                initComponent(this);
                try {
                    Thread.sleep(100);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });
        thread.start();
    }

    public void initComponent(JFrame frame) {
        BufferedImage image1 = new BufferedImage(Data.WIDTH, Data.HEIGHT, BufferedImage.TYPE_INT_RGB);

        JPanel backPanel = new JPanel(new BorderLayout());
        backPanel.setSize(600, 600);
        backPanel.add(new PixelBlockDrawing(image1), "Center");

        frame.add(backPanel);
        frame.setJMenuBar(getBar());
        frame.addMouseMotionListener(new Mouse(PixelBlockDrawing.status, cells));
        frame.setVisible(true);
    }

    public JMenuBar getBar() {
        JMenuBar bar = new JMenuBar();
        start = new JMenuItem("开始");
        start.addActionListener(this);
        stop = new JMenuItem("结束");
        stop.addActionListener(this);
        random = new JMenuItem("随机");
        random.addActionListener(this);
        remove = new JMenuItem("清除");
        remove.addActionListener(this);
        bar.add(start);
        bar.add(stop);
        bar.add(random);
        bar.add(remove);
        return bar;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == start) {
            start();
        } else if (e.getSource() == random) {
            random();
        } else if (e.getSource() == remove) {
            remove();
        } else if (e.getSource() == stop) {
            flag = 1;
        }
    }

    public void remove() {
        for (int i = 0; i < Data.WIDTH / Data.SIZE + 1; i++) {
            for (int j = 0; j < Data.HEIGHT / Data.SIZE + 1; j++) {
                PixelBlockDrawing.drawPixelBlock(i * Data.SIZE, j * Data.SIZE, Data.SIZE, Data.SIZE, Color.BLACK, Color.WHITE);
            }
        }
    }
}