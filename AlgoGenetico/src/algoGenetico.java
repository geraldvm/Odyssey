import java.util.concurrent.ThreadLocalRandom;

public class algoGenetico {

    private SimpleList iniciales = new SimpleList();
    private SimpleList generacion = new SimpleList();
    private SimpleList frase = new SimpleList();

    private String letra;
    private int generaciones = 2;
    private int size = 8;

    /**
     * Función que aumenta el número de generaciones si los resultados son mal calificados
     */
    public void aumentarGeneraciones() {
        generaciones++;
    }

    /**
     * @param fraseIn : String que corresponde a la frase a completar
     * @param letraIn : Letra completa de la canción
     */
    public algoGenetico(String fraseIn, String letraIn) {
        letra = letraIn;
        String[] array = fraseIn.split(" ");
        for (String palabra: array) {
            frase.addLast(palabra);
        }
        generarIniciales();
    }

    /**
     * Función que genera la lista de objetos inicial basado en la letra completa de la canción
     */
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

    /**
     * Crea la lista de hijos según la cantidad de genereaciones definida
     * @return : Hijo con mayor fitness que se encuentra en la última generación
     */
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

    /**
     * Función que combina dos miembros de la generación anterior
     * @param a : Objeto padre a combinar
     * @param b : Segundo objeto padre
     * @return : Valor resultante
     */
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

    /**
     * Calcula el fitness basado en la cantidad de palabras de la frase inicial que se encuentran
     * @return : Hijo de la última generación con el mayor fitness
     */
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