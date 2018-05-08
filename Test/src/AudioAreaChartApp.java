
import javafx.application.Application;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.chart.AreaChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.scene.media.AudioSpectrumListener;
import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;
import javafx.stage.Stage;


/**
 * An area chart that shows audio spectrum of a music file being played.
 *
 * @sampleName Audio Area Chart
 * @preview preview.png
 * @see javafx.scene.chart.AreaChart
 * @see javafx.scene.chart.Chart
 * @see javafx.scene.chart.NumberAxis
 * @see javafx.scene.chart.XYChart
 * @see javafx.scene.media.AudioSpectrumListener
 * @see javafx.scene.media.Media
 * @see javafx.scene.media.MediaPlayer
 * @docUrl http://docs.oracle.com/javafx/2/charts/jfxpub-charts.htm Using JavaFX Charts Tutorial
 */
public class AudioAreaChartApp extends Application {

    private XYChart.Data<Number, Number>[] series1Data;
    private AudioSpectrumListener audioSpectrumListener;
    private static final String MEDIA_URL = "http://download.oracle.com/otndocs/products/javafx/oow2010-2.flv";
    private static final String AUDIO_URI = System.getProperty("demo.audio.url",
            "http://download.oracle.com/otndocs/javafx/JavaRap_Audio.mp4");
    private static MediaPlayer audioMediaPlayer;
    private static final boolean PLAY_AUDIO = Boolean.parseBoolean(
            System.getProperty("demo.play.audio", "true"));

    public AudioAreaChartApp() {
        audioSpectrumListener = new AudioSpectrumListener() {
            @Override
            public void spectrumDataUpdate(double timestamp, double duration,
                                           float[] magnitudes, float[] phases) {
                for (int i = 0; i < series1Data.length; i++) {
                    series1Data[i].setYValue(magnitudes[i] + 60);
                }
            }
        };
    }

    public void play() {
        startAudio();
    }

    @Override
    public void stop() {
        stopAudio();
    }

    public Parent createContent() {
        final NumberAxis xAxis = new NumberAxis(0, 128, 8);
        final NumberAxis yAxis = new NumberAxis(0, 50, 10);
        final AreaChart<Number, Number> ac = new AreaChart<>(xAxis, yAxis);
        // setup chart
        ac.getStylesheets().add(AudioAreaChartApp.class
                .getResource("AudioAreaChart.css").toExternalForm());
        ac.setLegendVisible(false);
        ac.setTitle("Live Audio Spectrum Data");
        ac.setAnimated(false);
        xAxis.setLabel("Frequency Bands");
        yAxis.setLabel("Magnitudes");
        yAxis.setTickLabelFormatter(new NumberAxis.DefaultFormatter(yAxis, null, "dB"));
        // add starting data
        XYChart.Series<Number, Number> series = new XYChart.Series<>();
        series.setName("Audio Spectrum");
        //noinspection unchecked
        series1Data = new XYChart.Data[(int) xAxis.getUpperBound()];
        for (int i = 0; i < series1Data.length; i++) {
            series1Data[i] = new XYChart.Data<Number, Number>(i, 50);
            series.getData().add(series1Data[i]);
        }
        ac.getData().add(series);
        return ac;
    }

    private void startAudio() {
        if (PLAY_AUDIO) {
            getAudioMediaPlayer().
                    setAudioSpectrumListener(audioSpectrumListener);
            getAudioMediaPlayer().play();
        }
    }

    private void stopAudio() {
        if (getAudioMediaPlayer().getAudioSpectrumListener() == audioSpectrumListener) {
            getAudioMediaPlayer().pause();
        }
    }

    private static MediaPlayer getAudioMediaPlayer() {
        if (audioMediaPlayer == null) {
            Media audioMedia = new Media(MEDIA_URL);
            audioMediaPlayer = new MediaPlayer(audioMedia);
            audioMediaPlayer.setCycleCount(MediaPlayer.INDEFINITE);
        }
        return audioMediaPlayer;
    }

    @Override public void start(Stage primaryStage) throws Exception {
        primaryStage.setScene(new Scene(createContent()));
        primaryStage.show();
        play();
    }

    /**
     * Java main for when running without JavaFX launcher
     */
    public static void main(String[] args) {
        launch(args);
    }
}