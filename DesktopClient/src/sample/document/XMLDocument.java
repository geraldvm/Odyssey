package sample.document;

import org.w3c.dom.Attr;
import org.w3c.dom.Document;
import org.w3c.dom.Element;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import java.io.File;

public class XMLDocument {



    public void newUser(String username, String password,
                        String name, String lastname,String age, String genre){
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

            TransformerFactory transformerFactory = TransformerFactory.newInstance();
            Transformer transformer = transformerFactory.newTransformer();
            DOMSource source = new DOMSource(document);

            StreamResult streamResult = new StreamResult(new File("temp.xml"));

            transformer.transform(source,streamResult);

            System.out.println("temp.xml sucessfully!\n");



        }catch (Exception e){};



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

            StreamResult streamResult = new StreamResult(new File("temp.xml"));

            transformer.transform(source,streamResult);

            System.out.println("temp.xml sucessfully!\n");



        }catch (Exception e){};

    }

}
