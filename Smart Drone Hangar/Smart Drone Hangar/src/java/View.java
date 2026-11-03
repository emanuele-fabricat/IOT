
import java.awt.Toolkit;
import javax.swing.JFrame;

public class View {
    private final JFrame frame = new JFrame("DroneView");

    public View() {
        frame.setSize(Toolkit.getDefaultToolkit().getScreenSize());
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }


}
    