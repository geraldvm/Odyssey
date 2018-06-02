package sample.document;

import org.w3c.dom.Attr;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import sample.DataStructures.SimpleList;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import java.io.File;

public class XMLDocument {

    public void newUser(String username, String password, String name, String lastname,String age, String genre){

        try{
            DocumentBuilderFactory documentBuilderFactory = DocumentBuilderFactory.newInstance();
            DocumentBuilder documentBuilder = documentBuilderFactory.newDocumentBuilder();
            Document document = documentBuilder.newDocument();
            Element head = document.createElement("NewUser");
            document.appendChild(head);
            Element element = document.createElement("User");
            head.appendChild(element);
            Attr attr = document.createAttribute("Username");
            attr.setValue(username);
            element.setAttributeNode(attr);
            attr = document.createAttribute("Password");
            attr.setValue(password);
            element.setAttributeNode(attr);
            attr = document.createAttribute("Name");
            attr.setValue(name);
            element.setAttributeNode(attr);
            attr = document.createAttribute("Lastname");
            attr.setValue(lastname);
            element.setAttributeNode(attr);
            attr = document.createAttribute("Age");
            attr.setValue(age);
            element.setAttributeNode(attr);
            attr = document.createAttribute("Genre");
            attr.setValue(genre);
            element.setAttributeNode(attr);
            attr = document.createAttribute("Friends");
            attr.setValue(" ");
            element.setAttributeNode(attr);

            TransformerFactory transformerFactory = TransformerFactory.newInstance();
            Transformer transformer = transformerFactory.newTransformer();
            DOMSource source = new DOMSource(document);

            String path = System.getProperty("user.home")+"/Music/Odyssey/temp/temp.xml";
            StreamResult streamResult = new StreamResult(new File(path));
            transformer.transform(source,streamResult);
            System.out.println("temp.xml sucessfully!\n");

        }catch (Exception e){e.printStackTrace();}

    }


    public void userVerification(String username,String password){
        try{
            DocumentBuilderFactory documentBuilderFactory = DocumentBuilderFactory.newInstance();
            DocumentBuilder documentBuilder = documentBuilderFactory.newDocumentBuilder();
            Document document = documentBuilder.newDocument();
            Element head = document.createElement("userVerification");
            document.appendChild(head);
            Element element = document.createElement("User");
            head.appendChild(element);
            Attr attr = document.createAttribute("Username");
            attr.setValue(username);
            element.setAttributeNode(attr);
            attr = document.createAttribute("Password");
            attr.setValue(password);
            element.setAttributeNode(attr);
            TransformerFactory transformerFactory = TransformerFactory.newInstance();
            Transformer transformer = transformerFactory.newTransformer();
            DOMSource source = new DOMSource(document);

            String path = System.getProperty("user.home")+"/Music/Odyssey/temp/temp.xml";
            StreamResult streamResult = new StreamResult(new File(path));

            transformer.transform(source,streamResult);

            System.out.println("temp.xml sucessfully!\n");

        }catch (Exception e){e.printStackTrace();}

    }

    public void modifySong(int numPista, int numDisco, String oldName, String newName, String artist, String album,String year, String lyrics, String genre, String score){
        try{
            DocumentBuilderFactory documentBuilderFactory = DocumentBuilderFactory.newInstance();
            DocumentBuilder documentBuilder = documentBuilderFactory.newDocumentBuilder();
            Document document = documentBuilder.newDocument();
            Element head = document.createElement("ModifyMetaData");
            document.appendChild(head);
            Element element = document.createElement("Song");
            head.appendChild(element);
            Attr attr = document.createAttribute("OldName");
            attr.setValue(oldName);
            element.setAttributeNode(attr);
            attr = document.createAttribute("NewName");
            attr.setValue(newName);
            element.setAttributeNode(attr);
            attr = document.createAttribute("Artist");
            attr.setValue(artist);
            element.setAttributeNode(attr);
            attr = document.createAttribute("Album");
            attr.setValue(album);
            element.setAttributeNode(attr);
            attr = document.createAttribute("Year");
            attr.setValue(year);
            element.setAttributeNode(attr);
            attr = document.createAttribute("Lyrics");
            attr.setValue(lyrics);
            element.setAttributeNode(attr);
            attr = document.createAttribute("Genre");
            attr.setValue(genre);
            element.setAttributeNode(attr);
            attr = document.createAttribute("Score");
            attr.setValue(score);
            element.setAttributeNode(attr);
            attr = document.createAttribute("Pista");
            attr.setValue(String.valueOf(numPista));
            element.setAttributeNode(attr);
            attr = document.createAttribute("Disco");
            attr.setValue(String.valueOf(numDisco));
            element.setAttributeNode(attr);

            TransformerFactory transformerFactory = TransformerFactory.newInstance();
            Transformer transformer = transformerFactory.newTransformer();
            DOMSource source = new DOMSource(document);

            String path = System.getProperty("user.home")+"/Music/Odyssey/temp/temp.xml";
            StreamResult streamResult = new StreamResult(new File(path));

            transformer.transform(source,streamResult);

            System.out.println("temp.xml sucessfully!\n");

        }catch (Exception e){e.printStackTrace();}

    }

    public void pageRequested(int pageNum,String type,String value){

        try{
            DocumentBuilderFactory documentBuilderFactory = DocumentBuilderFactory.newInstance();
            DocumentBuilder documentBuilder = documentBuilderFactory.newDocumentBuilder();
            Document document = documentBuilder.newDocument();
            Element head = document.createElement("pageRequested");
            document.appendChild(head);
            Element element = document.createElement("Page");
            head.appendChild(element);
            Attr attr = document.createAttribute("Num");
            attr.setValue(String.valueOf(pageNum));
            element.setAttributeNode(attr);
            attr = document.createAttribute("Type");
            attr.setValue(type);
            element.setAttributeNode(attr);
            attr = document.createAttribute("Value");
            attr.setValue(value);
            element.setAttributeNode(attr);
            TransformerFactory transformerFactory = TransformerFactory.newInstance();
            Transformer transformer = transformerFactory.newTransformer();
            DOMSource source = new DOMSource(document);

            String path = System.getProperty("user.home")+"/Music/Odyssey/temp/temp.xml";
            StreamResult streamResult = new StreamResult(new File(path));

            transformer.transform(source,streamResult);

            System.out.println("temp.xml sucessfully!\n");

        }catch (Exception e){e.printStackTrace();}
    }

    public void songRequested(String name){
        try{
            DocumentBuilderFactory documentBuilderFactory = DocumentBuilderFactory.newInstance();
            DocumentBuilder documentBuilder = documentBuilderFactory.newDocumentBuilder();
            Document document = documentBuilder.newDocument();
            Element head = document.createElement("songRequested");
            document.appendChild(head);
            Element element = document.createElement("Song");
            head.appendChild(element);
            Attr attr = document.createAttribute("Name");
            attr.setValue(name);
            element.setAttributeNode(attr);
            TransformerFactory transformerFactory = TransformerFactory.newInstance();
            Transformer transformer = transformerFactory.newTransformer();
            DOMSource source = new DOMSource(document);

            String path = System.getProperty("user.home")+"/Music/Odyssey/temp/temp.xml";
            StreamResult streamResult = new StreamResult(new File(path));

            transformer.transform(source,streamResult);

            System.out.println("temp.xml sucessfully!\n");
        }catch (Exception e){e.printStackTrace();}
    }

    public void deleteSong(String name){
        try{
            DocumentBuilderFactory documentBuilderFactory = DocumentBuilderFactory.newInstance();
            DocumentBuilder documentBuilder = documentBuilderFactory.newDocumentBuilder();
            Document document = documentBuilder.newDocument();
            Element head = document.createElement("deleteSong");
            document.appendChild(head);
            Element element = document.createElement("Song");
            head.appendChild(element);
            Attr attr = document.createAttribute("Name");
            attr.setValue(name);
            element.setAttributeNode(attr);
            TransformerFactory transformerFactory = TransformerFactory.newInstance();
            Transformer transformer = transformerFactory.newTransformer();
            DOMSource source = new DOMSource(document);

            String path = System.getProperty("user.home")+"/Music/Odyssey/temp/temp.xml";
            StreamResult streamResult = new StreamResult(new File(path));

            transformer.transform(source,streamResult);

            System.out.println("temp.xml sucessfully!\n");

        }catch (Exception e){e.printStackTrace();}
    }

    public void sendMSG(String sender,String receiver,String song){
        try{
            DocumentBuilderFactory documentBuilderFactory = DocumentBuilderFactory.newInstance();
            DocumentBuilder documentBuilder = documentBuilderFactory.newDocumentBuilder();
            Document document = documentBuilder.newDocument();
            Element head = document.createElement("newMsg");
            document.appendChild(head);
            Element element = document.createElement("MSG");
            head.appendChild(element);
            Attr attr = document.createAttribute("Sender");
            attr.setValue(sender);
            element.setAttributeNode(attr);
            attr = document.createAttribute("Receiver");
            attr.setValue(receiver);
            element.setAttributeNode(attr);
            attr = document.createAttribute("Song");
            attr.setValue(song);
            element.setAttributeNode(attr);

            TransformerFactory transformerFactory = TransformerFactory.newInstance();
            Transformer transformer = transformerFactory.newTransformer();
            DOMSource source = new DOMSource(document);

            String path = System.getProperty("user.home")+"/Music/Odyssey/temp/temp.xml";
            StreamResult streamResult = new StreamResult(new File(path));

            transformer.transform(source,streamResult);

            System.out.println("temp.xml sucessfully!\n");

        }catch (Exception e){e.printStackTrace();}

    }
    public void spotifyRequested(String song){
        try{
            DocumentBuilderFactory documentBuilderFactory = DocumentBuilderFactory.newInstance();
            DocumentBuilder documentBuilder = documentBuilderFactory.newDocumentBuilder();
            Document document = documentBuilder.newDocument();
            Element head = document.createElement("spotifyRequested");
            document.appendChild(head);
            Element element = document.createElement("Song");
            head.appendChild(element);
            Attr attr = document.createAttribute("Name");
            attr.setValue(song);
            element.setAttributeNode(attr);
            TransformerFactory transformerFactory = TransformerFactory.newInstance();
            Transformer transformer = transformerFactory.newTransformer();
            DOMSource source = new DOMSource(document);

            String path = System.getProperty("user.home")+"/Music/Odyssey/temp/temp.xml";
            StreamResult streamResult = new StreamResult(new File(path));

            transformer.transform(source,streamResult);

            System.out.println("temp.xml sucessfully!\n");

        }catch (Exception e){e.printStackTrace();}

    }
}
