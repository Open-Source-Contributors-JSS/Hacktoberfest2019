using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Windows.Forms;

namespace MaquinaCasino
{
    public partial class Form1 : Form
    {
        // Inicialización de las imágenes que vamos a utilizar para mostrar en la máquina
        Image i7 = Image.FromFile("C:\\5to Semestre\\SSPA\\MaquinaCasino\\7.jpg");
        Image diamante = Image.FromFile("C:\\5to Semestre\\SSPA\\MaquinaCasino\\diamante.jpg");
        Image corazon = Image.FromFile("C:\\5to Semestre\\SSPA\\MaquinaCasino\\corazon.jpg");
        Image dados = Image.FromFile("C:\\5to Semestre\\SSPA\\MaquinaCasino\\dados.jpg");
        // Fin de inicialización de imágenes

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
        }

        public void ReiniciaCambio() // Función para restablecer los valores de cambio (y sus asociados)
        {
            labelCambio.Text = "Cambio: $0";
            label_1.Text = "$1: 0";
            label_2.Text = "$2: 0";
            label_5.Text = "$5: 0";
            label_10.Text = "$10: 0";
            label_20.Text = "$20: 0";
        } // Fin ReiniciaCambio()

        public void Premios() // Función para el control de los premios, en cada opción se suman los créditos y se muestra un mensaje en pantalla que avisa sí hubo premio
        {
            if (pictureBox_1.Image == i7 && pictureBox_2.Image == i7 && pictureBox_3.Image == i7) // 3 - 7's
            {
                creditos += 50;
                MessageBox.Show("**Has ganado 50 Créditos** Se agregarán a tus créditos", "!GANASTE¡");
            }
            else if (pictureBox_1.Image == diamante && pictureBox_2.Image == diamante && pictureBox_3.Image == diamante) // 3 Diamantes
            {
                creditos += 25;
                MessageBox.Show("**Has ganado 25 Créditos** Se agregarán a tus créditos", "!GANASTE¡");
            }
            else if (pictureBox_1.Image == corazon && pictureBox_2.Image == corazon && pictureBox_3.Image == corazon) // 3 Corazones
            {
                creditos += 10;
                MessageBox.Show("**Has ganado 10 Créditos** Se agregarán a tus créditos", "!GANASTE¡");
            }
            else if (pictureBox_1.Image == dados && pictureBox_2.Image == dados && pictureBox_3.Image == dados) // 3 Dados
            {
                creditos += 3;
                MessageBox.Show("**Has ganado 3 Créditos** Se agregarán a tus créditos", "!GANASTE¡");
            }
            else if (pictureBox_1.Image == i7 && pictureBox_2.Image == i7 || pictureBox_2.Image == i7 && pictureBox_3.Image == i7 || pictureBox_1.Image == i7 && pictureBox_3.Image == i7) // 2 - 7´s
            {
                creditos += 15;
                MessageBox.Show("**Has ganado 15 Créditos** Se agregarán a tus créditos", "!GANASTE¡");
            }
            else if (pictureBox_1.Image == diamante && pictureBox_2.Image == diamante || pictureBox_2.Image == diamante && pictureBox_3.Image == diamante || pictureBox_1.Image == diamante && pictureBox_3.Image == diamante) // 2 Diamantes
            {
                creditos += 10;
                MessageBox.Show("**Has ganado 10 Créditos** Se agregarán a tus créditos", "!GANASTE¡");
            }
            else if (pictureBox_1.Image == corazon && pictureBox_2.Image == corazon || pictureBox_2.Image == corazon && pictureBox_3.Image == corazon || pictureBox_1.Image == corazon && pictureBox_3.Image == corazon) // 2 Corazones
            {
                creditos += 5;
                MessageBox.Show("**Has ganado 5 Créditos** Se agregarán a tus créditos", "!GANASTE¡");
            }
            else if (pictureBox_1.Image == dados && pictureBox_2.Image == dados || pictureBox_2.Image == dados && pictureBox_3.Image == dados || pictureBox_1.Image == dados && pictureBox_3.Image == dados) // 2 Dados
            {
                creditos += 1;
                MessageBox.Show("**Has ganado 1 Crédito** Se agregarán a tus créditos", "!GANASTE¡");
            }
        } // Fin Premios()

        Random r; // Ayudará a elegir un número random para seleccionar la combinación
        int rnd; // Guardaremos el entero producido por Random r

        int creditos = 0; // Variable para guardar la cantidad total de los créditos
        int cont = 0; // Variable para decidir con qué imágenes iniciar en la máquina

        public void Resultado(Image i1, Image i2, Image i3) // Función para imprimir la combinación final
        {
            pictureBox_1.Image = i1;
            pictureBox_2.Image = i2;
            pictureBox_3.Image = i3;
        } // Fin Resultado()

        private void ButtonJugar_Click(object sender, EventArgs e) // Evento de Click en el botón Jugar
        {
            r = new Random(); // Inicializamos el Random

            if (creditos >= 7) // Sí la cantidad de créditos es mayor o igual a 7
            {
                creditos -= 7; // Disminuimos 7 créditos que corresponderían a 1 juego

                labelCreditos.Text = "Creditos: " + creditos.ToString(); // Reasignamos el nombre del label

                labelCreditos.Refresh(); // Actualizamos el label

                // Animación de la máquina

                rnd = r.Next(1, 5); // Asignamos a rnd un valor aleatorio entre 1 y 4, incluidos ambos

                cont = rnd; // Variable cont que nos ayudará a cambiar de ciclo de imágenes

                for (int i = 0; i < 90; i++) // Ciclo de cambio de imágenes por grupo de 3
                {
                    Thread.Sleep(i); // Detenemos el proceso con i, esto para qu4 cada vez sea más lento, hasta llegar a la decisión final
                    if (cont == 1)
                    {
                        pictureBox_1.Image = i7;
                        pictureBox_2.Image = diamante;
                        pictureBox_3.Image = corazon;
                        cont++; // Aumentamos cont para cambiar de grupo de imágenes
                    }
                    else if (cont == 2)
                    {
                        pictureBox_1.Image = diamante;
                        pictureBox_2.Image = corazon;
                        pictureBox_3.Image = dados;
                        cont++; // Aumentamos cont para cambiar de grupo de imágenes
                    }
                    else if (cont == 3)
                    {
                        pictureBox_1.Image = corazon;
                        pictureBox_2.Image = dados;
                        pictureBox_3.Image = diamante;
                        cont++; // Aumentamos cont para cambiar de grupo de imágenes
                    }
                    else if (cont == 4)
                    {
                        pictureBox_1.Image = dados;
                        pictureBox_2.Image = i7;
                        pictureBox_3.Image = corazon;
                        cont = 1; // Aumentamos cont para cambiar de grupo de imágenes
                    }

                    // Actualizamos los pictureBox's de la combinación con la nueva secuencia de imágenes
                    pictureBox_1.Refresh();
                    pictureBox_2.Refresh();
                    pictureBox_3.Refresh();
                } // Fin ciclo de imágenes

                rnd = r.Next(1, 41); // Asignamos a rnd un valor entre 1 y 40 (incluyéndolos) para la selección de la combinación

                switch (rnd) // Combinaciones posibles
                {
                    case 1:

                        Resultado(i7, i7, i7);

                        break;

                    case 2:

                        Resultado(i7, i7, diamante);

                        break;

                    case 3:

                        Resultado(i7, i7, corazon);

                        break;

                    case 4:

                        Resultado(i7, i7, dados);

                        break;

                    case 5:

                        Resultado(i7, diamante, corazon);

                        break;

                    case 6:

                        Resultado(i7, diamante, dados);

                        break;

                    case 7:

                        Resultado(i7, corazon, diamante);

                        break;

                    case 8:

                        Resultado(i7, corazon, diamante);

                        break;

                    case 9:

                        Resultado(i7, dados, diamante);

                        break;

                    case 10:

                        Resultado(i7, dados, corazon);

                        break;

                    case 11:

                        Resultado(diamante, diamante, diamante);

                        break;

                    case 12:

                        Resultado(diamante, diamante, i7);

                        break;

                    case 13:

                        Resultado(diamante, diamante, corazon);

                        break;

                    case 14:

                        Resultado(diamante, diamante, dados);

                        break;

                    case 15:

                        Resultado(diamante, i7, corazon);

                        break;

                    case 16:

                        Resultado(diamante, i7, dados);

                        break;

                    case 17:

                        Resultado(diamante, corazon, i7);

                        break;

                    case 18:

                        Resultado(diamante, corazon, dados);

                        break;

                    case 19:

                        Resultado(diamante, dados, i7);

                        break;

                    case 20:

                        Resultado(diamante, dados, corazon);

                        break;

                    case 21:

                        Resultado(corazon, corazon, corazon);

                        break;

                    case 22:

                        Resultado(corazon, corazon, i7);

                        break;

                    case 23:

                        Resultado(corazon, corazon, diamante);

                        break;

                    case 24:

                        Resultado(corazon, corazon, dados);

                        break;

                    case 25:

                        Resultado(corazon, i7, diamante);

                        break;

                    case 26:

                        Resultado(corazon, i7, dados);

                        break;

                    case 27:

                        Resultado(corazon, diamante, i7);

                        break;

                    case 28:

                        Resultado(corazon, diamante, dados);

                        break;

                    case 29:

                        Resultado(corazon, dados, i7);

                        break;

                    case 30:

                        Resultado(corazon, dados, diamante);

                        break;

                    case 31:

                        Resultado(dados, dados, dados);

                        break;

                    case 32:

                        Resultado(dados, dados, i7);

                        break;

                    case 33:

                        Resultado(dados, dados, diamante);

                        break;

                    case 34:

                        Resultado(dados, dados, corazon);

                        break;

                    case 35:

                        Resultado(dados, i7, diamante);

                        break;

                    case 36:

                        Resultado(dados, i7, corazon);

                        break;

                    case 37:

                        Resultado(dados, diamante, i7);

                        break;

                    case 38:

                        Resultado(dados, diamante, corazon);

                        break;

                    case 39:

                        Resultado(dados, corazon, i7);

                        break;

                    case 40:

                        Resultado(dados, corazon, diamante);

                        break;
                } // Fin Combinaciones posibles

                // Una vez seleccionado la combinación, actualizaremos nuevamente los pictureBox´s de la combinación
                pictureBox_1.Refresh();
                pictureBox_2.Refresh();
                pictureBox_3.Refresh();

                // Fin cambio de imagenes

                Premios(); // Llamamos a la función Premios() para saber si hemos ganado un premio

                labelCreditos.Text = "Creditos: " + creditos.ToString(); // En caso de haber ganado, esta instrucción nos ayuda a actualizar el label de créditos, sino vuelve a imprimir el valor de créditos que tenía
            }
        }

        int creditosStock = 0; // Variable para guardar lso créditos seleccionados que aún no han sido ingresados

        public void CambioStock() // Función para cambiar el label de Agregar créditod
        {
            labelAgregaC.Text = "Creditos para agregar: " + creditosStock.ToString(); // Instrucción para el cambio de label
        }

        public void Actualiza() // Función que nos ayuda a encapsular 2 funciones con instrucciones
        {
            CambioStock(); // Llamada a función que cambia el label de Agregar créditos
            ReiniciaCambio(); // Llamada a la función que reunucua los valores de Cambio y sus asiciados
        }

        private void Button_1_Click(object sender, EventArgs e) // Evento de Click del botón $1
        {
            creditosStock += 1; // Agregamos 1 crédito
            Actualiza(); // Llamada a la función que cambia los labels de Agrega créditos y cambio
        }

        private void Button_2_Click(object sender, EventArgs e) // Evento de Click del botón $2
        {
            creditosStock += 2; // Agregamos 2 créditos
            Actualiza(); // Llamada a la función que cambia los labels de Agrega créditos y cambio
        }

        private void Button_5_Click(object sender, EventArgs e) // Evento de Click del botón $5
        {
            creditosStock += 5; // Agregamos 5 créditos
            Actualiza(); // Llamada a la función que cambia los labels de Agrega créditos y cambio
        }

        private void Button_10_Click(object sender, EventArgs e) // Evento de Click del botón $10
        {
            creditosStock += 10; // Agregamos 10 créditos
            Actualiza(); // Llamada a la función que cambia los labels de Agrega créditos y cambio
        }

        private void ButtonAggCdt_Click(object sender, EventArgs e) // Evento de Click en el botón Agregar Crédito
        {
            creditos += creditosStock; // Agregamos la cantidad de Créditos en Stock a Créditos
            labelCreditos.Text = "Creditos: " + creditos.ToString(); // Cambiamos el label de crédito
            creditosStock = 0; // Igualamos créditosStock a 0 ya que se han ingresado a la máquina
            CambioStock(); // Llamamos a la función que cambia el label de Agregar Créditos
        }

        int[] monedas; // Arreglo que contendrá las monedas que se podrán utilizar para dar cambio
        int[] sol; // Arreglo que nos guardará el vector solución
        int aux = 0; // Variable que nos ayudará a indicar la posición en la que se agregarán las monedas
        int m1, m2, m5, m10, m20; // Variables en donde se guardarán las cantidades de las monedas de cada valor

        private void ButtonDarCambio_Click(object sender, EventArgs e) // Evento Click del botón Dar Cambio
        {
            if (creditos > 0) // Sí hay créditos de los cuales dar cambio
            {
                aux = 0; // Igualamos nuestra variable auxiliar en 0

                m1 = 0; m2 = 0; m5 = 0; m10 = 0; m20 = 0; // Igualamos las variables que contendrán las cantidades de las monedas de cada valor

                monedas = new int[5] { 0, 0, 0, 0, 0 }; // Inicializamos el arreglo con el tamaño de 5 monedas
                auxMon = new List<int>(); // Inicializamos la lista auxiliar de monedas

                monedas[aux++] = 1; // Ingresamos en la primera posición del arreglo la moneda de 1, que es la que siempre estará activa y aumentamos aux para que la próxima casilla disponible sea la siguiente
                if (checkBox_2.Checked == true) // Si la casiila de la moneda de 2 está activa
                {
                    monedas[aux] = 2; // Agremamos la moneda de 2 en la posición siguiente
                    aux++; // Aumentamos aux para que la príxima casilla disponivle sea la siguiente
                }
                if (checkBox_5.Checked == true)
                {
                    monedas[aux] = 5; // Agremamos la moneda de 5 en la posición siguiente
                    aux++; // Aumentamos aux para que la príxima casilla disponivle sea la siguiente
                }
                if (checkBox_10.Checked == true)
                {
                    monedas[aux] = 10; // Agremamos la moneda de 10 en la posición siguiente
                    aux++; // Aumentamos aux para que la príxima casilla disponivle sea la siguiente
                }
                if (checkBox_20.Checked == true)
                {
                    monedas[aux] = 20; // Agremamos la moneda de 20 en la posición siguiente
                }

                monedas = monedas.Where(i => i != 0).ToArray(); // Eliminanos los elementos que sean 0 (las monedas que su casilla no esta marcada)

                DarCambio(); // Llamamos a la función Dar Cambio

                sol = new int[auxSol.Count]; // Inicializamos el vector solución con la cantidad de elementos que tiene la lista auxiliar solución

                aux = 0; // Igualamos nuestra variable auxiliar a 0 para ayudarnos a ingresar los elementos en el vector solución desde la posición inicial

                foreach (int i in auxSol) // Para cada elemento en la lista auxiliar solución
                {
                    sol[aux++] = i; // En la posición en aux agregaremos el elemento

                    if (i == 1) // Si el elemento es un 1
                        m1++; // Aumentamos nuestro contador de monedas de 1
                    else if (i == 2) // Si el elemento es un 2
                        m2++; // Aumentamos nuestro contador de monedas de 2
                    else if (i == 5) // Si el elemento es un 5
                        m5++; // Aumentamos nuestro contador de monedas de 5
                    else if (i == 10) // Si el elemento es un 10
                        m10++; // Aumentamos nuestro contador de monedas de 10
                    else if (i == 20) // Si el elemento es un 20
                        m20++; // Aumentamos nuestro contador de monedas de 20
                } // Fin Para cada

                ActualizaCambio(); // Llamamos a la función que cambia las labels de cambio y sus asociados
            } // Fin si hay creditos
        } // Fin Evento botón Dar Cambio

        public void ActualizaCambio() // Función para cambiar las labels de cambio
        {
            // Reasignamos el texto de cada label
            labelCambio.Text = "Cambio: $" + creditos.ToString();
            label_1.Text = "$1: " + m1.ToString();
            label_2.Text = "$2: " + m2.ToString();
            label_5.Text = "$5: " + m5.ToString();
            label_10.Text = "$10: " + m10.ToString();
            label_20.Text = "$20: " + m20.ToString();

            creditos = 0; // Como dimos el cambio, los créditos se igualan a 0
            labelCreditos.Text = "Creditos: 0"; // Actualizamos el label de créditos
        } // Fin ActualizaCambio()

        int creditosAux; // Variable auxiliar que guardará la cantidad de créditos
        List<int> auxSol; // Lista auxiliar de solución
        List<int> auxMon; // Lista auxiliar para el manejo de las monedas en el proceso de DarCambio()
        int auxM; // Variable auxiliar que guardará la moneda actual

        public void DarCambio() // Algoritmo voraz de Dar Cambio
        {
            creditosAux = creditos; // Igualamos creditosAux con la cantidad de créditos real
            auxSol = new List<int>(); // Inicializamos la lista auxiliar de solución

            foreach(int x in monedas) // Para cada elemento en monedas
            {
                auxMon.Add(x); // Agregamos el elemento en la lista auxiliar de monedas
            }

            while(auxMon.Count > 0) // Mientras haya elementos en la lista auxiliar de monedas
            {
                auxM = auxMon.Last(); // Asignamos a la variable auxM el último elemento de la lista auxiliar de monedas, que en cada caso será la moneda mayor

                if(auxM <= creditosAux) // Si auxM es menos o igual que creditosAux
                {
                    auxSol.Add(auxM); // Agregamos una moneda de la cantidad de auxM a la lista auxiliar de solución
                    creditosAux -= auxM; // Restamos la cantidad de auxM a creditosAux

                    if(creditosAux == 0) // Si Ya no hay créditos que restar
                    {
                        return; // Termina
                    }
                }
                else // Si la moneda sobrepasa la cantidad de creditosAux
                {
                    auxMon.Remove(auxM); // Quita la moneda del vector auxiliar de monedas
                }
            } // FIn Mientras
        } // Fin DarCambio()
    }
}
