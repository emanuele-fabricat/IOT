import java.awt.Font;

import javax.swing.JTextPane;

/**
 * Viewer
 */
public abstract class Viewer extends JTextPane {
    public Viewer() {
        super();
        this.setEditable(false);
        this.setFont(new Font("Arial", Font.PLAIN, 16));
        this.setVisible(true);
    }

    public void setString(String str){
        this.setText(str);
        upDate();
    }

    private void upDate(){
        this.repaint();
    }
    
}
