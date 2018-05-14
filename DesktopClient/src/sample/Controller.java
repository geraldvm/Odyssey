package sample;

import com.jfoenix.controls.*;
import javafx.application.Platform;

import javafx.beans.property.DoubleProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;

import javafx.scene.Node;
import javafx.scene.chart.*;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ToggleGroup;
import javafx.scene.image.ImageView;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;

import java.io.FileInputStream;
import java.io.IOException;
import java.net.URL;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.text.DecimalFormat;
import java.util.Random;
import java.util.ResourceBundle;


import javafx.scene.media.AudioSpectrumListener;
import javafx.scene.media.AudioEqualizer;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.util.Duration;

import sample.client.ClientThread;
import sample.document.XMLDocument;
public class Controller implements Initializable{
    @FXML private ImageView userArrow, playerArrow, libraryArrow,socialArrow;
    @FXML private ImageView playerBtn,libraryBtn,socialBtn;
    @FXML private AnchorPane loginPanel,logoutPanel,userPanel, playerPanel, libraryPanel, socialPanel;
    @FXML private JFXComboBox<String> comboBoxGenre;
    @FXML private JFXTextField nameText,lastnameText,usernameText,ageText;
    @FXML private JFXTextField userLogText;
    @FXML private JFXPasswordField passwordLogText,passwordText;
    @FXML private JFXProgressBar progressBar;
    @FXML private JFXSlider slider;
    @FXML private ImageView playButton,pauseButton;
    @FXML private Label totalDuration,currentDuration;

    @FXML JFXListView<String> musicList;
    @FXML JFXComboBox<String> comboSearch;
    @FXML JFXTextField searchText;





    @FXML private Circle circle;
    private int sessionPanel;
    private DecimalFormat formatter = new DecimalFormat("00.00");
    private Duration totalTime;
    private Reproductor player = new Reproductor();

    private XMLDocument myXML = new XMLDocument();


    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {//"Constructor" de las variables de la interfaz
        nameText.addEventFilter(KeyEvent.ANY, handlerLetters);
        lastnameText.addEventFilter(KeyEvent.ANY, handlerLetters);
        ageText.addEventFilter(KeyEvent.ANY,handlerNumbers);
        searchText.addEventFilter(KeyEvent.ANY,handlerLetters);

        comboBoxGenre.getItems().addAll("Pop","Rock","Reggae","R&B",
                "Hip-Hop","Dance-Hall","House");
        comboSearch.getItems().addAll("Song","Artist","Album","Lyrics");


        sessionPanel = 0;

        playerBtn.setDisable(true);
        libraryBtn.setDisable(true);
        socialBtn.setDisable(true);






        progressBar.progressProperty().bind(slider.valueProperty().divide(100));


        ClientThread.initClient();

    }



    public void onExitButtonClicked(MouseEvent event){
        Platform.exit();
        ClientThread.client.disconnected();
        System.exit(0);

    }
    public void onUserButtonClicked(MouseEvent event){
        if(logoutPanel.isVisible()&&sessionPanel==1){
            userArrow.setVisible(false);
            logoutPanel.setVisible(false);

        }else if(sessionPanel==0){
            userPanel.setVisible(false);
            loginPanel.setVisible(true);
            userArrow.setVisible(true);
            playerArrow.setVisible(false);
            playerPanel.setVisible(false);
            libraryArrow.setVisible(false);
            libraryPanel.setVisible(false);
            socialArrow.setVisible(false);
            socialPanel.setVisible(false);

        }
        else if((!logoutPanel.isVisible())&&sessionPanel==1){
            userArrow.setVisible(true);
            logoutPanel.setVisible(true);
            playerArrow.setVisible(false);
            playerPanel.setVisible(false);
            libraryArrow.setVisible(false);
            libraryPanel.setVisible(false);
            socialArrow.setVisible(false);
            socialPanel.setVisible(false);
        }

    }
    public void onPlayerButtonClicked(MouseEvent event){
        if(playerPanel.isVisible()){
            playerArrow.setVisible(false);
            playerPanel.setVisible(false);
        }else {

            userArrow.setVisible(false);
            userPanel.setVisible(false);
            loginPanel.setVisible(false);
            logoutPanel.setVisible(false);
            playerArrow.setVisible(true);
            playerPanel.setVisible(true);
            libraryArrow.setVisible(false);
            libraryPanel.setVisible(false);
            socialArrow.setVisible(false);
            socialPanel.setVisible(false);
            startPlayer();

        }

    }
    public void onLibraryButtonClicked(MouseEvent event){
        if(libraryPanel.isVisible()){
            libraryArrow.setVisible(false);
            libraryPanel.setVisible(false);
        }else {
            userArrow.setVisible(false);
            userPanel.setVisible(false);
            loginPanel.setVisible(false);
            logoutPanel.setVisible(false);
            playerArrow.setVisible(false);
            playerPanel.setVisible(false);
            libraryArrow.setVisible(true);
            libraryPanel.setVisible(true);
            socialArrow.setVisible(false);
            socialPanel.setVisible(false);
        }

    }
    public void onSocialButtonClicked(MouseEvent event){
        if(socialPanel.isVisible()){
            socialArrow.setVisible(false);
            socialPanel.setVisible(false);
        }else {
            userArrow.setVisible(false);
            userPanel.setVisible(false);
            loginPanel.setVisible(false);
            logoutPanel.setVisible(false);
            playerArrow.setVisible(false);
            playerPanel.setVisible(false);
            libraryArrow.setVisible(false);
            libraryPanel.setVisible(false);
            socialArrow.setVisible(true);
            socialPanel.setVisible(true);
        }

    }

    EventHandler<KeyEvent> handlerLetters = new EventHandler<KeyEvent>() {
        private boolean willConsume = false;
        @Override
        public void handle(KeyEvent event) {
            Object tempO = event.getSource();
            if(willConsume){
                event.consume();
            }String temp = event.getCode().toString();
            //If toma lo que se teclea  Compara si es minucula o mayusculas, si no es espacio entonces no muestra nada
            if(!event.getCode().toString().matches("[a-zA-Z]")&&event.getCode()!= KeyCode.BACK_SPACE
                    && event.getCode()!=KeyCode.SHIFT){
                if(event.getEventType()==KeyEvent.KEY_PRESSED){
                    willConsume=true;
                }else if(event.getEventType()==KeyEvent.KEY_RELEASED){
                    willConsume=false;
                }
            }

        }
    };

    EventHandler<KeyEvent> handlerNumbers = new EventHandler<KeyEvent>() {
        private boolean willConsume = false;
        private int maxLength = 2;

        @Override
        public void handle(KeyEvent event) {
            JFXTextField temp = (JFXTextField) event.getSource();

            if(willConsume){
                event.consume();
            }
            if(!event.getText().matches("[0-9]")&& event.getCode()!=KeyCode.BACK_SPACE){
                if(event.getEventType() == KeyEvent.KEY_PRESSED){
                    willConsume=true;
                }else if(event.getEventType()==KeyEvent.KEY_RELEASED){
                    willConsume=false;
                }
            }
            if(temp.getText().length()>maxLength-1){
                if(event.getEventType()==KeyEvent.KEY_PRESSED){
                    willConsume=true;
                }else if(event.getEventType()==KeyEvent.KEY_RELEASED){
                    willConsume=false;
                }
            }

        }
    };

    public void onComboGenreChanged(ActionEvent event){


        if(comboBoxGenre.getValue().equals("Hip-Hop")){
                nameText.setDisable(true);


        }

    }

    public void onSaveButton(ActionEvent event){
        if(nameText.getText().isEmpty()||usernameText.getText().isEmpty()||
                lastnameText.getText().isEmpty()||ageText.getText().isEmpty()||
                passwordText.getText().isEmpty()){
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Save Profile");
            alert.setContentText("Please, fill out the entire blank");
            alert.show();
        }else {
            System.out.println(usernameText.getText().toString());
            System.out.println(nameText.getText());
            System.out.println(lastnameText.getText());
            System.out.println(ageText.getText());
            System.out.println(passwordText.getText());

            myXML.newUser(usernameText.getText().toString(),
                    passwordText.getText().toString(),nameText.getText().toString(),
                    lastnameText.getText().toString(),ageText.getText().toString(),
                    comboBoxGenre.getValue().toString());
            ClientThread.client.sendMSG("SI FUNCIONA LLORE CONMGO PAPI");

            try {
                String data = readFileAsString("/home/gerald/Documents/I Sem 2018/Datos 2/Odyssey/DesktopClient/temp.xml");
                ClientThread.client.sendMSG(data);
            } catch (Exception e) {
                e.printStackTrace();
            }

            //sendFile("sample.fxml");/home/gerald/Documents/I Sem 2018/Datos 2/Odyssey/DesktopClient/temp.xml


            playerBtn.setDisable(false);
            libraryBtn.setDisable(false);
            socialBtn.setDisable(false);
            userPanel.setVisible(false);
            logoutPanel.setVisible(true);
            sessionPanel = 1;
        }

    }

    public void onLoginButton(ActionEvent event){
        if(userLogText.getText().isEmpty()||passwordLogText.getText().isEmpty()){
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Login");
            alert.setContentText("Please, fill out the entire blank");
            alert.show();
        }else {
            System.out.println(userLogText.getText().toString());
            System.out.println(passwordLogText.getText());
            myXML.userVerification(userLogText.getText().toString(),
                    passwordLogText.getText().toString());
            try {
                String data = readFileAsString("/home/gerald/Documents/I Sem 2018/Datos 2/Odyssey/DesktopClient/temp.xml");
                ClientThread.client.sendMSG(data);
            } catch (Exception e) {
                e.printStackTrace();
            }
            playerBtn.setDisable(false);
            libraryBtn.setDisable(false);
            socialBtn.setDisable(false);
            loginPanel.setVisible(false);
            loginPanel.setVisible(false);
            logoutPanel.setVisible(true);
            sessionPanel = 1;
        }
        //Abrir ventana cerrar sesion
    }
    public void onRegisterButton(ActionEvent event){
        loginPanel.setVisible(false);
        userPanel.setVisible(true);

    }
    public void onLogoutButton(ActionEvent event){
        loginPanel.setVisible(true);
        userPanel.setVisible(false);
        logoutPanel.setVisible(false);
        playerBtn.setDisable(true);
        libraryBtn.setDisable(true);
        socialBtn.setDisable(true);
        sessionPanel=0;

    }


    private void startPlayer(){
        player.cargarArchivo("sound.wav");
        player.iniciar();
        currentDuration.setText(String.valueOf(formatter.format(0)));

        player.getMediaPlayer().currentTimeProperty().addListener((observable, oldValue, newValue) -> {
            slider.valueProperty().setValue(newValue.divide(totalTime.toMillis()).toMillis() * 100.0);
            currentDuration.setText(String.valueOf(formatter.format(newValue.toSeconds())));
        });

        player.getMediaPlayer().setOnReady(() -> {
            totalTime = player.getMediaPlayer().getMedia().getDuration();
            totalDuration.setText(String.valueOf(formatter.format(Math.floor(totalTime.toSeconds()))));
        });

        slider.valueProperty().addListener((ov) -> {
            if (slider.isValueChanging()) {
                if (null != player.getMediaPlayer()) {
                    player.getMediaPlayer().seek(totalTime.multiply(slider.valueProperty().getValue() / 100.0));
                } else
                    slider.valueProperty().setValue(0);
            }
        });
    }

    public void onPlayButton(MouseEvent event){
        System.out.println("PLAY");
        player.play();
        playButton.setVisible(false);
        pauseButton.setVisible(true);

        player.getSpec(circle,player.getMediaPlayer());

    }

    public void onPauseButton(MouseEvent event) {
        System.out.println("PAUSE");
        player.pause();
        pauseButton.setVisible(false);
        playButton.setVisible(true);



    }


    public static String readFileAsString(String fileName)throws Exception
    {
        String data = "";
        data = new String(Files.readAllBytes(Paths.get(fileName)));
        return data;
    }

    public void onNextButton(MouseEvent event){
        setMusicList(0);
    }
    public void onPrevButton(MouseEvent event){
        setMusicList(2);
    }
    private void setMusicList(int i){
        int listSize = musicList.getItems().size();
        //comboBoxGenre.getItems().remove(1);
        for(int x =0;x<listSize;x++){
            musicList.getItems().remove(0);
        }
        if(i==0){
            musicList.getItems().addAll("Havana","Wake Me Up","Helicopter", "Tsunami",
                    "Tololouse","We are Loud","Animals","Levels",
                    "Party Rock","Thinking out Loud");

        }else{
            musicList.getItems().addAll("November Rain","Patience","Welcome to the Jungle",
                    "Don't Cry","Crazy","I dont wanna miss a thing",
                    "Hole in my soul", "Always","Smells Like Teen Spirit",
                    "Zombie");
        }
    }
    public void onSelectedSong(MouseEvent even){
        String song= musicList.getSelectionModel().getSelectedItem();
        System.out.println(song);

    }

    public void onPlaySong(ActionEvent e){
        String song= musicList.getSelectionModel().getSelectedItem();
        System.out.println("Play: "+song+".mp3");

    }
    public void onDeleteSong(ActionEvent e){
        String song= musicList.getSelectionModel().getSelectedItem();
        System.out.println("Delete: "+song+".mp3");

    }
    public void onModifySong(ActionEvent e){
        String song= musicList.getSelectionModel().getSelectedItem();
        System.out.println("Modify: "+song);

    }

    public void searchSongBy(MouseEvent e){
        System.out.println("Search by: "+comboSearch.getValue());
        System.out.println("Searching..."+searchText.getText());

    }





}
