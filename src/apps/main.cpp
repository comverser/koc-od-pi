//#include "koc_od_pi_intf.h"
//#include <iostream> // std::cout
//#include <unistd.h> // sleep()
#include <gtk/gtk.h>

GtkWidget *g_lbl_hello;
GtkWidget *g_lbl_count;

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "win_main.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);

    g_lbl_hello = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_hello"));
    g_lbl_count = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_count"));

    g_object_unref(builder);

    gtk_widget_show(window);
    gtk_main();

    return 0;
}

void on_btn_hello_clicked()
{
    static unsigned int count = 0;
    char str_count[30] = {0};
    
    gtk_label_set_text(GTK_LABEL(g_lbl_hello), "Hello, world!");
    count++;
    sprintf(str_count, "%d", count);
    gtk_label_set_text(GTK_LABEL(g_lbl_count), str_count);
}

// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}

/*
int main(void)
{
    koc_od_pi::intf object;

    if ( object.setup() )
    {
        std::cout << "error" << std::endl;
        return 1;
    }

    int num = 0;
    while (1)
    {
        if (num == 32)
        {
            num = 0;
        }
        object.ttl(num);
        sleep(5);
        num++;
    }

    return 0;

}

int main (int argc, char **argv)
{
    GtkWidget *window;

    gtk_init (&argc, &argv);

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "Hello world !");
    g_signal_connect (G_OBJECT (window), "destroy", gtk_main_quit, NULL);

    gtk_widget_show_all (window);
    gtk_main ();

    return 0;
}
*/
