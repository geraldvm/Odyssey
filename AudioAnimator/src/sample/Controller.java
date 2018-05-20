package sample;

import javafx.event.ActionEvent;

public class Controller {

    public void btnPresed(ActionEvent actionEvent) {
        Reproductor player = Reproductor.getInstance();
        player.pause();
    }

}

