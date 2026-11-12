public class ViewerPanel extends javax.swing.JPanel {
    private java.util.List<Viewer> viewers = new java.util.ArrayList<>();
    public ViewerPanel() {
        initComponents();
    }

    private void initComponents() {
        this.setLayout(new java.awt.GridLayout());
        this.viewers.add(new StatusView());
        this.viewers.add(new DistanceView());
        this.viewers.add(new LogView());
        for (Viewer v : viewers) {
            this.add((java.awt.Component) v);
            v.setString("prova");
        }
    }

    

}
