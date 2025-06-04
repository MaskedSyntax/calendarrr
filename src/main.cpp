#include <gtk/gtk.h>

// Global variable to hold the label widget
GtkWidget *dateLabel;

// Callback function to handle the day selection
void on_day_selected(GtkCalendar *calendar) {
    guint year, month, day;
    gtk_calendar_get_date(calendar, &year, &month, &day);
    gchar *date_str = g_strdup_printf("Selected Date: %02d/%02d/%d", day, month + 1, year);
    gtk_label_set_text(GTK_LABEL(dateLabel), date_str);
    g_free(date_str);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Create a new window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Calendarrr");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    // Create a vertical box to hold widgets
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Create a calendar widget
    GtkWidget *calendar = gtk_calendar_new();
    g_signal_connect(calendar, "day-selected", G_CALLBACK(on_day_selected), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), calendar, TRUE, TRUE, 0);

    // Create a label to display the selected date
    dateLabel = gtk_label_new("Selected Date: ");
    gtk_box_pack_start(GTK_BOX(vbox), dateLabel, FALSE, FALSE, 0);

    // Connect the window close event
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Show all widgets
    gtk_widget_show_all(window);

    // Start the GTK main loop
    gtk_main();

    return 0;
}

