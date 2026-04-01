#include "../includes/tarea.h"
#include <stdlib.h>




void CreaCsv(){

    int i, puntaje, cantidadCompetencias;
    char *nombres[500] = {
        "Juan","Diego","Jaime","Pedro","Luis","Carlos","Jorge","Andres","Miguel","Fernando",
        "Ricardo","Sergio","Alberto","Manuel","Rafael","Pablo","Hector","Eduardo","Victor","Mario",
        "Raul","Oscar","Gabriel","Emilio","Adrian","Julio","Enrique","Roberto","Daniel","Francisco",
        "Esteban","Tomas","Ignacio","Matias","Nicolas","Felipe","Sebastian","Cristian","Mauricio","Claudio",
        "Patricio","Rodrigo","Ivan","Gonzalo","Cesar","Leonardo","Maximiliano","Hugo","Ruben","Alonso",
        "Bruno","Axel","Benjamin","Lucas","Agustin","Dario","Elias","Fabian","German","Horacio",
        "Ismael","Javier","Kevin","Lautaro","Marcelo","Nelson","Orlando","Paulo","Ramiro","Salvador",
        "Tobias","Ulises","Valentin","Walter","Xavier","Yahir","Zaid","Aaron","Abel","Adolfo",
        "Alan","Alex","Alfredo","Amador","Anibal","Ariel","Armando","Arturo","Baltazar","Bartolo",
        "Beltran","Bernardo","Blas","Braulio","Camilo","Casimiro","Ciro","Conrado","Damaso","Dante",
        "David","Demetrio","Dionisio","Domingo","Edgar","Edmundo","Efrain","Eladio","Eliseo","Eloy",
        "Ernesto","Eusebio","Evaristo","Fausto","Federico","Fermin","Fidel","Flavio","Fortunato","Gaspar",
        "Gerardo","Gilberto","Guillermo","Gustavo","Heriberto","Hilario","Homero","Iker","Inocencio","Irving",
        "Isaac","Isidro","Jacinto","Jael","Jairo","Jesus","Joel","Jonas","Jonathan","Josue",
        "Juanito","Justo","Kenny","Leandro","Lisandro","Lorenzo","Luciano","Marcos","Martin","Mateo",
        "Melchor","Moises","Nestor","Norberto","Octavio","Omar","Onofre","Osvaldo","Pascual","Primo",
        "Quentin","Quirino","Ramon","Reinaldo","Renato","Rigoberto","Rodolfo","Rolando","Rosendo","Ruperto",
        "Santiago","Saul","Silvio","Teodoro","Timoteo","Tristan","Ubaldo","Valerio","Vicente","Wilfredo",
        "Yago","Zacarias","Abraham","Adan","Agapito","Aitor","Alarico","Alejandro","Alfonso","Alvaro",
        "Amancio","Amaro","Ambrosio","Anastasio","Anselmo","Antonio","Aquiles","Arcadio","Aristides","Arnoldo",
        "Arsenio","Aureliano","Aurelio","Balbino","Basilio","Benito","Bonifacio","Borja","Calixto","Candido",
        "Casiano","Cayetano","Ceferino","Celestino","Cipriano","Cirilo","Clemente","Cornelio","Cosme","Cristobal",
        "Dalmacio","Dario","Desiderio","Dimas","Donato","Doroteo","Edelmiro","Eleuterio","Elpidio","Emerico",
        "Encarnacion","Epifanio","Erasmo","Eriberto","Erostrato","Escolastico","Estanislao","Eugenio","Eulogio","Eusebio",
        "Exequiel","Fabricio","Facundo","Faustino","Felix","Feliciano","Felicisimo","Fernando","Florencio","Froilan",
        "Gabino","Gael","Galileo","Genaro","Geronimo","Gervasio","Gildardo","Gines","Gregorio","Guido",
        "Gumersindo","Hernan","Higinio","Hipolito","Humberto","Ildefonso","Indalecio","Inigo","Isaias","Jacobo",
        "Jenaro","Jeremias","Jeremias","Jeronimo","Joaquin","Jordy","Josafat","Josias","Juanmanuel","Julian",
        "Justino","Ladislao","Laureano","Leocadio","Leoncio","Leopoldo","Lino","Lisardo","Loren","Lucio",
        "Macario","Magno","Manases","Marcial","Mariano","Mario","Marino","Mauro","Maximo","Meliton",
        "Menandro","Miguelangel","Modesto","Nabor","Nazario","Nemesio","Nicanor","Nicomedes","Noe","Nolasco",
        "Noriel","Obdulio","Olegario","Olimpio","Orestes","Orfelio","Ovidio","Pablo","Pancracio","Pascasio",
        "Pelayo","Perfecto","Petronilo","Plutarco","Policarpo","Prudencio","Quico","Quintin","Raimundo","Rancel",
        "Recaredo","Remigio","Renzo","Reyes","Rito","Robinson","Rogelio","Romualdo","Ruperto","Sabino",
        "Salomon","Samir","Sancho","Sansón","Saturnino","Segismundo","Servando","Severiano","Silverio","Siro",
        "Socorro","Solano","Sotero","Tadeo","Tarsicio","Telmo","Teofilo","Tiburcio","Tito","Toribio",
        "Trifon","Ulpiano","Urbano","Valentin","Valeriano","Venancio","Ventura","Vidal","Victoriano","Vigilio",
        "Waldo","Washington","Wilmer","Ximeno","Yandel","Yosef","Zebedeo","Zenon","Zosimo","Abner","Adriel","Aldo","Alejo","Alonso","Amir","Anuar","Ariel","Aron","Asael",
        "Augusto","Bastian","Bautista","Belisario","Benicio","Benjamín","Boris","Candelario","Casandro","Cayetano",
        "Ciro","Claudio","Clemente","Cosme","Cristóbal","Damián","Dario","Darwin","Delfín","Demian",
        "Dennis","Desiderio","Dimas","Dionel","Dorian","Eber","Edwin","Efren","Elian","Elio",
        "Elmer","Emanuel","Emiliano","Emir","Enzo","Erasmo","Erick","Eros","Estanislao","Eugenio",
        "Evaristo","Ezequiel","Fabricio","Fausto","Favio","Feliciano","Fidel","Filemon","Flavio","Fortunato",
        "Franco","Freddy","Gael","Gaston","Genaro","Geronimo","Gian","Gino","Giovanni","Gonzalo",
        "Guido","Hector","Hernan","Hugo","Ibrahim","Iker","Isael","Isaias","Ismael","Israel",
        "Ivan","Jairo","Jared","Javier","Jaziel","Jean","Joaquin","Joel","Jonatan","Jordan",
        "Josue","Juan","Julian","Junior","Justino","Kadir","Kai","Karim","Kevin","Khalil",
        "Kristian","Lautaro","Leandro","Leon","Leonardo","Levi","Liam","Lisandro","Logan","Lorenzo",
        "Lucas","Luciano","Luis","Manuel","Marcelo","Marcos","Mariano","Mario","Martin","Mateo",
        "Matias"};

    char *apellidos[500] = {
        "Perez","Gonzalez","Rodriguez","Fernandez","Lopez","Martinez","Sanchez","Ramirez","Torres","Flores",
        "Rivera","Gomez","Diaz","Vasquez","Castro","Ortiz","Reyes","Morales","Rojas","Gutierrez",
        "Silva","Alvarez","Mendoza","Ruiz","Jimenez","Moreno","Herrera","Medina","Aguilar","Vargas",
        "Romero","Suarez","Cortes","Ramos","Navarro","Molina","Campos","Vega","Castillo","Guerrero",
        "Delgado","Paredes","Fuentes","Cabrera","Salazar","Espinoza","Valenzuela","Araya","Contreras","Sepulveda",
        "Muñoz","Figueroa","Palma","Bravo","Maldonado","Leiva","Saavedra","Tapia","Escobar","Soto",
        "Carrasco","Peña","Bustos","Garrido","Parra","Zamora","Quiroz","Alarcon","Aravena","Sandoval",
        "Lagos","Calderon","Arias","Valdes","Olivares","Carrillo","Montoya","Benitez","Baeza","Becerra",
        "Barrientos","Bustamante","Carmona","Cano","Cardenas","Carvajal","Catalan","Cifuentes","Cornejo","Cuevas",
        "Donoso","Duran","Elgueta","Espinosa","Farias","Godoy","Hernandez","Ibarra","Jara","Lara",
        "Lobos","Madrid","Marin","Mella","Mendez","Meza","Miranda","Moya","Nuñez","Orellana",
        "Oyarzun","Pavez","Pizarro","Poblete","Ponce","Riquelme","Riveros","Roldan","Salinas","Sanhueza",
        "Santana","Serrano","Solis","Toledo","Toro","Urrutia","Vergara","Villalobos","Villanueva","Yañez",
        "Zuniga","Acevedo","Acosta","Agurto","Aguirre","Albornoz","Almonacid","Altamirano","Andrade","Antileo",
        "Arevalo","Avendaño","Bahamondes","Barriga","Bastias","Benavides","Berrios","Bertin","Betancourt","Bianchi",
        "Blanco","Borquez","Brito","Caceres","Cañete","Cantuarias","Caroca","Carrera","Cataldo","Catrileo",
        "Cea","Cespedes","Chacon","Chavez","Cisternas","Claveria","Coñuecar","Concha","Correa","Covarrubias",
        "Curinao","DeLaCruz","DelReal","DelValle","Droguett","Echeverria","Encina","Escalona","Espejo","Faundez",
        "Ferrada","Foncea","Fredes","Galaz","Gallardo","Gallegos","Gamez","Gatica","Gaete","Guerra",
        "Henriquez","Hidalgo","Huerta","Illanes","Inostroza","Jeldres","Jerez","Jofre","Krause","Larrain",
        "Larrondo","Latorre","Lazcano","Lemus","Letelier","Leyton","Lillo","Lira","Loyola","Lucero",
        "Mancilla","Mardones","Marquez","Matamala","Mayorga","Melendez","Merino","Millan","Moncada","Monje",
        "Montenegro","Montero","Moraga","Mora","Morgado","Navarrete","Neira","Olguin","Oliva","Olmos",
        "Opazo","Ovalle","Palacios","Pastene","Patiño","Pedreros","Pezo","Pincheira","Pino","Plaza",
        "Polanco","Quezada","Quintana","Quinteros","Retamal","Rifo","Rios","Robles","Roco","Rozas",
        "Rubio","Saez","Salas","Salgado","Santander","Santibañez","Santos","Sarabia","Sobarzo","Suazo",
        "Tejos","Torrealba","Troncoso","Ugarte","Ulloa","Ureta","Uribe","Urra","Valdebenito","Valdivia",
        "Valencia","Velasquez","Venegas","Verdugo","Vidal","Villagra","Villaroel","Villavicencio","Zamorano","Zapata",
        "Zepeda","Aburto","Aguilera","Alcayaga","Alquinta","Alveal","Andaur","Angulo","Antinao","Arcos",
        "Arriagada","Arroyo","Astorga","Aviles","Ayala","Balboa","Barahona","Barra","Barrios","Bascur",
        "Belmar","Bernal","Bocaz","Bolados","Bordeu","Burgos","Cabello","Calfuqueo","Calquin","Campillay",
        "Canales","Cariman","Cartes","Carvallo","Catricura","Cayuqueo","Ceballos","Celis","Cerda","Chacana",
        "Chiguay","Cofre","Coloma","Colque","Cordova","Cortinez","Crespo","Curilef","DeLaFuente","DelCanto",
        "DelFierro","DelSolar","Dominguez","Durán","Elizalde","Escudero","Espina","Estay","Eyzaguirre","Fuentealba",
        "Fuenzalida","Gajardo","Galindo","Gandarillas","Garay","Griffero","Huenchullan","Huenuman","Huenupi","Huichalaf",
        "Huichaman","Huincaman","Huincaleo","Huilipan","Huilical","Huilinao","Ibacache","Ilabaca","Iturriaga","Jeldrez",
        "Klocker","Krebs","Krumm","Kuschel","Labra","Lagos2","Lahsen","Lamas","Landarretche","Larenas",
        "Larraguibel","Larrea","Larrondo2","Larruy","Lastra","Latapiat","Lautaro","Lavados","Leal","Leiton",
        "Lemarie","Leonelli","Lepe","Lermanda","Lizana","Lobos2","Lois",
        "Longueira","Lorca","Loyola2","Lozada","Lucchini","Luksic","Luna","Luengo","Luque","Lusardi","Macaya","Macchiavello","Mackenna",
        "Maira","Maiz","Maluenda","Manosalva","Mansilla","Mantegazza","Mardoff","Marfull","Marambio","Marcone",
        "Marenzi","Mariangel","Marinovic","Marisio","Markovic","Marquet","Marro","Marsan","Martic","Marusic",
        "Massardo","Massone","Mateluna","Maturana","Maureira","Maza","Mazzoni","Mecina","Medel","Mejias",
        "Melgarejo","Mellado","Melivilu","Melivilu2","Melita","Mena","Menchaca","Meneses","Merello","Merlet",
        "Meruane","Mesina","Messina","Meyer","Mieres","Millar","Mimica","Minoletti","Mir","Miralles",
        "Mirosevic","Mladinic","Moena","Moffat","Mogollon","Moller","Monardes","Mondaca","Monreal","Monsalve",
        "Montalba","Montes","Montesinos","Montiel","Montt","Morales2","Morandé","Morand","Moreno2","Moriconi",
        "Moris","Moroni","Mossó","Moya2","Moyano","Mujica","Muller","Mulet","Munita","Munoz2",
        "Mura","Musalem","Nadal","Nail","Nancucheo","Naranjo","Narvaez","Navarrete2","Navarro2","Nazer",
        "Neculman","Negron","Nelson","Neriz","Nervo","Neyra","Nilo","Nino","Nisbet","Noguera",
        };

    srand(time(0));
    

    
    FILE *archivo;

    archivo = fopen("db/deportistas.csv", "w");

    fprintf(archivo,"ID,Nombre,Equipo,Puntaje,CantidadCompetencias\n");

    for (i=0; i<500; i++){
        puntaje=rand()%100;
        cantidadCompetencias= rand()%5000;
        fprintf (archivo, "%d, %s %s, Huachipato, %d, %d\n", i, nombres[i], apellidos[i], puntaje, cantidadCompetencias);
    }


    fclose(archivo);
}

void OrdenaCsv(){
    
}

void BuscarPorID(){

}

void Ranking(){

}