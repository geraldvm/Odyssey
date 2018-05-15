package sample.document;

public class Message {
    private String sender;
    private String song;


    public Message(String sender, String song){
        this.sender=sender;
        this.song=song;
    }
    public String getMessage(){
        return "From: "+this.sender+". Hey you need to listen this song: "+this.song;
    }

}
