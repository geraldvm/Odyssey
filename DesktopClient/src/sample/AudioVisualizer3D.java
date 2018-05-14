package sample;


import java.io.File;
import java.util.Random;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.media.AudioSpectrumListener;
import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

public class AudioVisualizer3D extends Application {
    private MediaPlayer mediaPlayer;

    public static void main(String[] args) {
        Application.launch(args);
    }

    @Override
    public void start(final Stage primaryStage) {
        primaryStage.setTitle("Playing Audio");
        primaryStage.centerOnScreen();
        primaryStage.initStyle(StageStyle.TRANSPARENT);

        Group root = new Group();
        Scene scene = new Scene(root, 551, 270, Color.rgb(0, 0, 0, 0));

        Media media = new Media(new File("sound.wav").toURI().toString());

        if (mediaPlayer != null) {
            mediaPlayer.stop();
        }

        mediaPlayer = new MediaPlayer(media);

        // Maintained Inner Class for Tutorial, could be changed to lambda
        mediaPlayer.setAudioSpectrumListener(new AudioSpectrumListener() {
            @Override
            public void spectrumDataUpdate(double timestamp, double duration,
                                           float[] magnitudes, float[] phases) {

                int i = 0;
                int x = 10;
                int y = 150;
                final Random rand = new Random(System.currentTimeMillis());
                for (float phase : phases) {
                    int red = rand.nextInt(255);
                    int green = rand.nextInt(255);
                    int blue = rand.nextInt(255);

                    Circle circle = new Circle(10);
                    circle.setCenterX(x + i);
                    circle.setCenterY(y + (phase * 100));
                    circle.setFill(Color.rgb(red, green, blue, .70));

                    i += 5;
                }
            }
        });

        mediaPlayer.setOnReady(mediaPlayer::play);

        mediaPlayer.stop();
        mediaPlayer.play();
        mediaPlayer.pause();

        primaryStage.setScene(scene);
        primaryStage.show();
    }
}