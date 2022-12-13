import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.time.Instant;
import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        var listener=new TimePrinter();
        var timer=new Timer(1000,listener);
        timer.start();
        //显示一个信息面板，其中包含yes/no和消息choose one
        JOptionPane.showConfirmDialog(null,"Quit program?");
        System.exit(0);
    }
}

class TimePrinter implements ActionListener {
    @Override
    public void actionPerformed(ActionEvent e) {
        System.out.println("At the tone,the time is "+ Instant.ofEpochMilli(e.getWhen()));
        Toolkit.getDefaultToolkit().beep();
    }
}