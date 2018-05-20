package sample;

import javafx.scene.media.AudioSpectrumListener;
import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Sphere;
import java.io.*;


public class Reproductor {

    private static Reproductor instance = null;
    private Sphere circle;
    private Circle sombra;
    private Media hit;
    private MediaPlayer mediaPlayer;

    public static Reproductor getInstance() {
        if (instance == null) {
            instance = new Reproductor();
        }
        return instance;
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

