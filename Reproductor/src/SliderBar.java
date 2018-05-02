import javafx.beans.property.DoubleProperty;
import javafx.scene.control.ProgressBar;
import javafx.scene.control.Slider;
import javafx.scene.layout.StackPane;

public class SliderBar extends StackPane {

    private Slider slider = new Slider();

    private ProgressBar progressBar = new ProgressBar();

    public SliderBar() {
        getChildren().addAll(progressBar, slider);
        bindValues();
    }
    private void bindValues(){
        progressBar.prefWidthProperty().bind(slider.widthProperty());
        progressBar.progressProperty().bind(slider.valueProperty().divide(100));
    }

    public DoubleProperty sliderValueProperty() {
        return slider.valueProperty();
    }

    public boolean isTheValueChanging() {
        return slider.isValueChanging();
    }
}