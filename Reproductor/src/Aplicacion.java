import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import javafx.util.Duration;
import java.text.DecimalFormat;

public class Aplicacion extends Application {

    private final Button playButton = new Button("Play");
    private final Button pauseButton = new Button("Pause");

    private final Label totalDuration = new Label();
    private final Label currentDuration = new Label();
    private final DecimalFormat formatter = new DecimalFormat("00.00");
    private final SliderBar timeSlider = new SliderBar();
    private Duration totalTime;


    @Override
    public void start(Stage primaryStage) {

        VBox root = new VBox(10);
        root.setAlignment(Pos.CENTER);
        root.setStyle("-fx-background-color: #0e8125");

        HBox playPause = new HBox(playButton, pauseButton);
        HBox sliderBox = new HBox(currentDuration,timeSlider,totalDuration);

        root.getChildren().addAll(sliderBox, playPause);
        Scene scene = new Scene(root, 275, 100);

        Reproductor player = new Reproductor();
        player.cargarArchivo("./cancion.mp3");
        player.iniciar();

        currentDuration.setText(String.valueOf(formatter.format(0)));

        player.getMediaPlayer().currentTimeProperty().addListener((observable, oldValue, newValue) -> {
            timeSlider.sliderValueProperty().setValue(newValue.divide(totalTime.toMillis()).toMillis() * 100.0);
            currentDuration.setText(String.valueOf(formatter.format(newValue.toSeconds())));
        });

        player.getMediaPlayer().setOnReady(() -> {
            totalTime = player.getMediaPlayer().getMedia().getDuration();
            totalDuration.setText(String.valueOf(formatter.format(Math.floor(totalTime.toSeconds()))));
        });

        timeSlider.sliderValueProperty().addListener((ov) -> {
            if (timeSlider.isTheValueChanging()) {
                if (null != player.getMediaPlayer()) {
                    player.getMediaPlayer().seek(totalTime.multiply(timeSlider.sliderValueProperty().getValue() / 100.0));
                } else
                    timeSlider.sliderValueProperty().setValue(0);
            }
        });

        playButton.setOnAction(e -> player.play());

        pauseButton.setOnAction(e -> player.pause());

        primaryStage.setTitle("Reproductor");
        primaryStage.setScene(scene);
        primaryStage.show();

    }

    public static void main(String[] args) {
        launch(args);

    }

}
