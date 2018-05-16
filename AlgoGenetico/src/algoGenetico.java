import java.util.concurrent.ThreadLocalRandom;

public class algoGenetico {

    private SimpleList iniciales = new SimpleList();
    private SimpleList generacion = new SimpleList();
    private SimpleList frase = new SimpleList();

    private String letra;
    private int generaciones = 2;
    private int size = 8;

    public void aumentarGeneraciones() {
        generaciones++;
    }

    public algoGenetico(String fraseIn, String letraIn) {
        letra = letraIn;
        String[] array = fraseIn.split(" ");
        for (String palabra: array) {
            frase.addLast(palabra);
        }
        generarIniciales();
    }

    private void generarIniciales() {
        String[] palabras = letra.split(" ");
        String[] aux = new String[size];
        int j = 0;
        for (String palabra : palabras) {
            aux[j] = palabra;
            if (j+1 == size) {
                j = -1;
                iniciales.addLast(aux);
                aux = new String[size];
            }
            j++;
        }
    }

    public String[] generarHijos() {
        int primero = 0;
        int segundo = ThreadLocalRandom.current().nextInt(primero+1, iniciales.size-1);
        for (int j = 0; j < generaciones; j++) {
            for (int i = 0; i < iniciales.size; i++) {
                generacion.addLast(combinar((String[]) iniciales.show(primero),(String[]) iniciales.show(segundo)));
                segundo = ThreadLocalRandom.current().nextInt(primero+1, iniciales.size-1);
            }
            for (int i = 0; i < iniciales.size; i++) {
                iniciales.update(i,generacion.show(i));
            }
            if (j + 1 != generaciones) {
                generacion = new SimpleList();
            }
            primero = 0;
            segundo = ThreadLocalRandom.current().nextInt(primero+1, iniciales.size-1);
        }
        return buscarMejor();
    }

    private String[] combinar(String[] a, String[] b) {
        String[] res = new String[size];
        SimpleList indicesIgualesA = new SimpleList();
        SimpleList indicesIgualesB = new SimpleList();
        for (int i = 0; i < size; i++) {
            for (int x = 0; x < frase.size; x++) {
                if (frase.show(x).equals(a[i])) {
                    indicesIgualesA.addLast(i);
                }
                if (frase.show(x).equals(b[i])) {
                    indicesIgualesB.addLast(i);
                }
            }
        }
        for (int i = 0; i < size; i++) {
            if(indicesIgualesA.search(i)) {
                res[i] = a[i];
            } else {
                if (indicesIgualesB.search(i)) {
                    res[i] = b[i];
                } else {
                    if (i < size/2) {
                        res[i] = b[i];
                    } else {
                        res[i] = a[i];
                    }
                }
            }

        }
        return res;
    }

    private String[] buscarMejor() {
        int indice = 0;
        int fitnessMayor = 0;
        int fit = 0;
        String[] aux;
        for (int i = 0; i < iniciales.size; i++) {
            aux = (String[]) iniciales.show(i);
            for (String anAux : aux) {
                for (int x = 0; x < frase.size; x++) {
                    if (frase.show(x).equals(anAux)) {
                        fit++;
                    }
                }
            }
            if (fit > fitnessMayor) {
                fitnessMayor = fit;
                indice = i;
                fit = 0;
            }
        }
        return (String[]) generacion.show(indice);
    }

}