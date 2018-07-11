#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "Socio.h"
#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"
#include <string.h>

#include <gtk/gtk.h>


static int idiomaVista = VISTA_IDIOMA_ES;

static void opcionSocioABM (GtkWidget *widget,gpointer   data);
static void view_onRowActivated (GtkTreeView *treeview,GtkTreePath *path,GtkTreeViewColumn  *col, gpointer userdata);

static void finIngresoModificacion (GtkWidget *widget,gpointer   data);
static void finIngresoBaja (GtkWidget *widget,gpointer   data);
static void finIngresoAlta (GtkWidget *widget,gpointer   data);


static GtkWidget       *window;
static GtkBuilder      *builderEditUserWindow;


enum {
    ID,
    NOMBRE,
    APELLIDO,
    DNI,
    DESCRIPTION,
    COLOR,
    N_COLUMNS
};


static void on_window_main_destroy()
{
    gtk_main_quit();
}


int vista_init (int idioma)
{
    idiomaVista = idioma;
    gtk_init(0, 0);
    return 0;
}

void mostrarError(char *);

int vista_mostrarMenu()
{
    GtkBuilder* builder;
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "./ventana.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));

    GtkWidget *button;
    button = GTK_WIDGET(gtk_builder_get_object(builder, "btnSociosABM"));
    g_signal_connect (button, "clicked", G_CALLBACK (opcionSocioABM), NULL);

    button = GTK_WIDGET(gtk_builder_get_object(builder, "btnSalir"));
    g_signal_connect (button, "clicked", G_CALLBACK (on_window_main_destroy), NULL);


    g_signal_connect (window, "delete-event", G_CALLBACK (on_window_main_destroy), NULL);

    gtk_widget_show(window);
    gtk_main(); // bloqueante

    return 0;
}


static void opcionSocioABM (GtkWidget *widget,gpointer   data)
{
    cont_listarSocios();
}



void vista_mostrarSocios(ArrayList* pListaSocios)
{
    int i;
    Socio* auxSocio;

    GtkListStore*      model;
    GtkWidget*         view;
    GtkTreeViewColumn* column;
    GtkWidget*         window;



    /* MODEL */
    model = gtk_list_store_new(N_COLUMNS,
                               G_TYPE_UINT,   /* ID */
                               G_TYPE_STRING,   /* NOMBRE */
                               G_TYPE_STRING,   /* APELLIDO */
                               G_TYPE_STRING,     /* DNI */
                               G_TYPE_STRING,   /* DESCRIPTION */
                               G_TYPE_STRING    /* COLOR */
                              );

    for(i=0;i<al_len(pListaSocios);i++)
    {
        auxSocio=al_get(pListaSocios,i);
        if(auxSocio->estado==SOCIO_ESTADO_ACTIVO)
        {
            auxSocio = al_get(pListaSocios,i);

            gtk_list_store_insert_with_values(model, NULL, -1,
                                      ID, soc_getId(auxSocio),
                                      NOMBRE, soc_getNombre(auxSocio),
                                      APELLIDO, soc_getApellido(auxSocio),
                                      DNI, soc_getDni(auxSocio),
                                      COLOR, "white",
                                      -1);

        }
    }


    /* VIEW treeview1*/
    builderEditUserWindow = gtk_builder_new();
    gtk_builder_add_from_file (builderEditUserWindow, "./ventanaEditar.glade", NULL);


    view = (GtkWidget*) gtk_builder_get_object(builderEditUserWindow, "treeview1");
    gtk_tree_view_set_model(GTK_TREE_VIEW(view), NULL); /* Detach model from view */
    gtk_tree_view_set_model(GTK_TREE_VIEW(view),GTK_TREE_MODEL(model));

    g_object_unref(model);


    column = gtk_tree_view_column_new_with_attributes("ID",
                                                      gtk_cell_renderer_text_new(),
                                                      "text", ID,
                                                      "background", COLOR,
                                                      NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(view), column);

    column = gtk_tree_view_column_new_with_attributes("Nombre",
                                                      gtk_cell_renderer_text_new(),
                                                      "text", NOMBRE,
                                                      "background", COLOR,
                                                      NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(view), column);

    column = gtk_tree_view_column_new_with_attributes("Apellido",
                                                      gtk_cell_renderer_text_new(),
                                                      "text", APELLIDO,
                                                      "background", COLOR,
                                                      NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(view), column);

    column = gtk_tree_view_column_new_with_attributes("DNI",
                                                      gtk_cell_renderer_text_new(),
                                                      "text", DNI,
                                                      "background", COLOR,
                                                      NULL);

    g_signal_connect(view, "row-activated", (GCallback) view_onRowActivated, NULL);

    gtk_tree_view_append_column(GTK_TREE_VIEW(view), column);


    GtkWidget *button;
    button = GTK_WIDGET(gtk_builder_get_object(builderEditUserWindow, "btnModificar"));
    g_signal_connect (button, "clicked", G_CALLBACK (finIngresoModificacion), NULL);

    button = GTK_WIDGET(gtk_builder_get_object(builderEditUserWindow, "btnAlta"));
    g_signal_connect (button, "clicked", G_CALLBACK (finIngresoAlta), NULL);

    button = GTK_WIDGET(gtk_builder_get_object(builderEditUserWindow, "btnBaja"));
    g_signal_connect (button, "clicked", G_CALLBACK (finIngresoBaja), NULL);

	window = GTK_WIDGET(gtk_builder_get_object(builderEditUserWindow, "window_main"));

	gtk_widget_show(window);


}


static void view_onRowActivated (   GtkTreeView        *treeview,
                                    GtkTreePath        *path,
                                    GtkTreeViewColumn  *col,
                                    gpointer            userdata)
{
    GtkTreeModel *model;
    GtkTreeIter   iter;
    GtkWidget* entry;
	gchar id[50];


    model = gtk_tree_view_get_model(treeview);

    if (gtk_tree_model_get_iter(model, &iter, path))
    {
        gchar *bufferTxt;
        gint bufferInt;

        gtk_tree_model_get(model, &iter, NOMBRE, &bufferTxt, -1);
        entry = GTK_WIDGET(gtk_builder_get_object(builderEditUserWindow, "txtName"));
        gtk_entry_set_text(GTK_ENTRY(entry),bufferTxt);
        g_free(bufferTxt);

        gtk_tree_model_get(model, &iter, APELLIDO, &bufferTxt, -1);
        entry = GTK_WIDGET(gtk_builder_get_object(builderEditUserWindow, "txtSurname"));
        gtk_entry_set_text(GTK_ENTRY(entry),bufferTxt);
        g_free(bufferTxt);

        gtk_tree_model_get(model, &iter, DNI, &bufferTxt, -1);
        entry = GTK_WIDGET(gtk_builder_get_object(builderEditUserWindow, "txtDni"));
        gtk_entry_set_text(GTK_ENTRY(entry),bufferTxt);
        g_free(bufferTxt);

        gtk_tree_model_get(model, &iter, ID, &bufferInt, -1);
        entry = GTK_WIDGET(gtk_builder_get_object(builderEditUserWindow, "txtId"));
        sprintf(id, "%d",bufferInt);
        g_print ("A row has been double-clicked! --- %s\n",id);
        gtk_entry_set_text(GTK_ENTRY(entry),id);


    }
  }



//_________________________________________________________________________________________________________


//******* ELMINAR eventos **************************************************************************************
static void finIngresoBaja (GtkWidget *widget,gpointer   data)
{
	GtkWidget* entry;

	char* textId;


    entry = GTK_WIDGET(gtk_builder_get_object(builderEditUserWindow, "txtId"));
  	textId = (char*)gtk_entry_get_text(GTK_ENTRY(entry));
    cont_bajaSocio(atoi(textId));


    // cierro la ventana
	GtkWidget* window = GTK_WIDGET(gtk_builder_get_object(builderEditUserWindow, "window_main"));
	gtk_window_close((GtkWindow*)window);

	g_object_unref (G_OBJECT (builderEditUserWindow)); // liberamos builder de la ventana


}




//******* EDITAR eventos **************************************************************************************
static void finIngresoModificacion (GtkWidget *widget,gpointer   data)
{
    GtkWidget* entry;
	char* textName;
	char* textSurname;
	char* textDNI;
	char* textId;

	printf("Tengo los datos, doy de alta un socio\r\n");

	entry = GTK_WIDGET(gtk_builder_get_object(builderEditUserWindow, "txtName"));
  	textName = (char*)gtk_entry_get_text(GTK_ENTRY(entry));

	entry = GTK_WIDGET(gtk_builder_get_object(builderEditUserWindow, "txtSurname"));
  	textSurname = (char*)gtk_entry_get_text(GTK_ENTRY(entry));

	entry = GTK_WIDGET(gtk_builder_get_object(builderEditUserWindow, "txtDni"));
  	textDNI = (char*)gtk_entry_get_text(GTK_ENTRY(entry));

    entry = GTK_WIDGET(gtk_builder_get_object(builderEditUserWindow, "txtId"));
  	textId = (char*)gtk_entry_get_text(GTK_ENTRY(entry));

	// validar
	//...

	cont_modificarSocio(textName,textSurname,textDNI,atoi(textId),0);

	GtkWidget* window = GTK_WIDGET(gtk_builder_get_object(builderEditUserWindow, "window_main"));
	gtk_window_close((GtkWindow*)window);

	g_object_unref (G_OBJECT (builderEditUserWindow)); // liberamos builder de la ventana
}




//******* ALTA eventos **************************************************************************************
static void finIngresoAlta (GtkWidget *widget,gpointer   data)
{
	GtkWidget* entry;
	char* textName;
	char* textSurname;
	char* textDNI;

	printf("Tengo los datos, doy de alta un socio\r\n");

	entry = GTK_WIDGET(gtk_builder_get_object(builderEditUserWindow, "txtName"));
  	textName = (char*)gtk_entry_get_text(GTK_ENTRY(entry));

	entry = GTK_WIDGET(gtk_builder_get_object(builderEditUserWindow, "txtSurname"));
  	textSurname = (char*)gtk_entry_get_text(GTK_ENTRY(entry));

	entry = GTK_WIDGET(gtk_builder_get_object(builderEditUserWindow, "txtDni"));
  	textDNI = (char*)gtk_entry_get_text(GTK_ENTRY(entry));

	// validar
	//...

	cont_altaSocio(textName,textSurname,textDNI);


    // cierro la ventana
	GtkWidget* window = GTK_WIDGET(gtk_builder_get_object(builderEditUserWindow, "window_main"));
	gtk_window_close((GtkWindow*)window);

	g_object_unref (G_OBJECT (builderEditUserWindow)); // liberamos builder de la ventana


}

//_________________________________________________________________________________________________________
