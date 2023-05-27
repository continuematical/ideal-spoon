import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;
import java.util.ArrayList;
import java.util.List;

public class Mouse implements MouseMotionListener {
    private boolean status[][];
    private ArrayList<List<Cell>> cells;

    public Mouse(boolean status[][], ArrayList<List<Cell>> cells) {
        this.status = status;
        this.cells = cells;
    }

    @Override
    public void mouseDragged(MouseEvent e) {
        int x = e.getX() / Data.SIZE;
        int y = e.getY() / Data.SIZE;
        PixelBlockDrawing.status[x][y] = true;
        cells.get(x).get(y).nextStatus = true;

        PixelBlockDrawing.drawPixelBlock(x * Data.SIZE, y * Data.SIZE, Data.SIZE, Data.SIZE, Color.white, Color.white);
    }

    @Override
    public void mouseMoved(MouseEvent e) {

    }
}
