import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;
import java.io.File;

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

}