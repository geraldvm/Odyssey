package sample;
import javafx.fxml.FXML;
import javafx.scene.chart.BarChart;
import javafx.scene.chart.XYChart;
import javafx.scene.media.AudioSpectrumListener;
import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;

import java.io.File;
import java.net.URL;
import java.util.Random;


public class Reproductor  {

    private
    Media hit;
    MediaPlayer mediaPlayer;

    public
    MediaPlayer getMediaPlayer() {
                return mediaPlayer;
    }

    void iniciar() {
        mediaPlayer = new MediaPlayer(hit);
    }

    void play() {

        mediaPlayer.play();
    }

    void cargarArchivo(String url) {
        hit = new Media(new File(url).toURI().toString());
    }

    void pause() {
        mediaPlayer.pause();
    }

    public void getSpec(Circle circle, MediaPlayer m) {
        this.mediaPlayer.setAudioSpectrumNumBands(128);
        this.mediaPlayer.setAudioSpectrumInterval(0.2);
        this.mediaPlayer.getAudioSpectrumThreshold();

        this.mediaPlayer.setAudioSpectrumListener(new AudioSpectrumListener() {
            @Override
            public void spectrumDataUpdate(double timestamp, double duration,
                                           float[] magnitudes, float[] phases) {



                int o = 0;
                float x = 50;
                int y = 50;


                final Random rand = new Random(System.currentTimeMillis());
                for (int i = 0; i < magnitudes.length; i++) {


                        int red = rand.nextInt(255);
                        int green = rand.nextInt(255);
                        int blue = rand.nextInt(255);
                        circle.setFill(Color.rgb(red, green, blue, .70));
                        System.out.println((magnitudes[i] - mediaPlayer.getAudioSpectrumThreshold()));
                        //circle.setCenterY((magnitudes[i] + 60.0) * -1.0);
                        circle.setRadius(50+((magnitudes[i] - mediaPlayer.getAudioSpectrumThreshold())*10));
                    /*cube[i].s.setY((magnitudes[i] + 60.01) * 1.5 + 1.0);
                    cube[i].s.setZ((magnitudes[i] + 60.01) * 0.8 + 1.0);
                    cubeXform[i].rx.setAngle((magnitudes[i] + 60.0) * 2.0);
                    cubeXform[i].ry.setAngle((magnitudes[i] + 60.0) * 2.1 + 10.0);
                    cubeXform[i].rz.setAngle((magnitudes[i] + 60.0) * 2.1 + 10.0);
                    cubeXform[i].setTranslateY((magnitudes[i] + 60.0) * -1.0);
                    */

                }
/*
                for (float phase : phases) {
                    if (i==50){
                        i=0;
                        int red = rand.nextInt(255);
                        int green = rand.nextInt(255);
                        int blue = rand.nextInt(255);
                        //System.out.println(phase*50);
                        //x += 0.5;



                        ///rcle.setLayoutX(x+i);
                        circle.setCenterX(i);
                        //circle.setLayoutY(y + (phase*200));
                        circle.setCenterY(y - (phase*100));
                        circle.setFill(Color.rgb(red, green, blue, .70));

                    }
                    else {
                        i += 1;
                        System.out.println(i);
                    }


                }*/
            }
        });
    }
}

