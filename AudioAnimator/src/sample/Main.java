package sample;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.scene.paint.PhongMaterial;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Sphere;
import javafx.stage.Stage;


public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception{

        Parent root = FXMLLoader.load(getClass().getResource("sample.fxml"));
        primaryStage.setTitle("Animador");
        primaryStage.setScene(new Scene(root, 300, 275));

        Sphere grafico = (Sphere) primaryStage.getScene().lookup("#grafico");
        Circle sombra = (Circle) primaryStage.getScene().lookup("#sombra");
        grafico.setRadius(50);
        grafico.setLayoutX(0);

        PhongMaterial material = new PhongMaterial();
        material.setDiffuseColor(Color.rgb(100, 255, 0));
        grafico.setMaterial(material);

        Reproductor player = Reproductor.getInstance();
        player.cargarArchivo("cancion.mp3");
        player.iniciar();
        player.setGrafico(grafico,sombra);
        player.play();

        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
