package sample.Media;
import javafx.fxml.FXML;
import javafx.scene.chart.BarChart;
import javafx.scene.chart.XYChart;
import javafx.scene.media.AudioSpectrumListener;
import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;
import javafx.scene.media.MediaView;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;

import java.io.File;
import java.net.URL;
import java.util.Random;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Sphere;

public class Reproductor  {


    private static Reproductor instance = null;
    private Sphere circle;
    private Circle sombra;
    private Media hit;
    private MediaPlayer mediaPlayer;

    public MediaPlayer getMediaPlayer() {
        return mediaPlayer;
    }

    public void iniciar() {

        mediaPlayer = new MediaPlayer(hit);

        mediaPlayer.setAudioSpectrumThreshold(128);
        mediaPlayer.setAudioSpectrumInterval(0.1);

        AudioSpectrumListener spectrumListener = (timestamp, duration, magnitudes, phases) -> {
            if (circle != null) {

                new Thread(() -> {
                    if (phases[0] == 0) {
                        phases[0] = 1;
                    }
                    sombra.setRadius(Math.abs(phases[0]*50));
                    circle.setRadius(128-Math.abs(phases[0]*50));
                }).start();
            }
        };

        mediaPlayer.setAudioSpectrumListener(spectrumListener);
    }

    public void play() {
        mediaPlayer.play();
    }

    public void cargarArchivo(String url) {
        hit = new Media(new File(url).toURI().toString());
    }

    public void pause() {
        mediaPlayer.pause();
    }

    public void setGrafico(Sphere grafico, Circle sombra) {
        this.circle = grafico;
        this.sombra = sombra;
    }

}


