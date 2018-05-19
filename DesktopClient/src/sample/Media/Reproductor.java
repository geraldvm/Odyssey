package sample;

import javafx.scene.media.AudioSpectrumListener;
import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import java.io.*;
import java.util.Random;


public class Reproductor {

    private static Reproductor instance = null;
    private Circle circle;
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

        final Random rand = new Random(System.currentTimeMillis());

        AudioSpectrumListener spectrumListener = (timestamp, duration, magnitudes, phases) -> {
            if (circle != null) {
                new Thread(() -> {
                    for (float phase : phases) {
                        System.out.println(128-Math.abs(phase*10));
                        int red = rand.nextInt(255);
                        int green = rand.nextInt(255);
                        int blue = rand.nextInt(255);
                        circle.setFill(Color.rgb(red, green, blue, .30));
                        circle.setRadius(128-Math.abs(phase*50));
                    }
                    try{
                        Thread.sleep(100);
                    } catch (InterruptedException e){
                        e.printStackTrace();
                    }
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

    public void setGrafico(Circle grafico) {
        this.circle = grafico;
    }

}

