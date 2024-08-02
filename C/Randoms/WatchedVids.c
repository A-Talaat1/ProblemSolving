#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Video {
    char *name;
    int unique_views;
} Video;

typedef struct Viewer {
    char *username;
    Video *watched_videos;
    int watched_videos_size;
} Viewer;

int count_views(Viewer **viewers, int viewers_size, char *video_name)
{
    // Waiting to be implemented
    int counter1 = 0, counter2 = 0, views = 0;
    
    for(counter1 = 0; counter1 < viewers_size; ++counter1)
    {
        Viewer *viewer = viewers[counter1];

        for(counter2 = 0; counter2 < (viewer->watched_videos_size); ++counter2)
        {
            if (!strcmp(video_name, (viewer->watched_videos[counter2].name)))
            {
                ++views;
            }
            
        }
    }

    return views;
}

#ifndef RunTests
int main()
{
    Video videos[] = { {.name = "Soccer", .unique_views = 500},
                       {.name = "Basketball", .unique_views = 1000} };
    Viewer viewer = {.username = "Dave", .watched_videos = videos,
                     .watched_videos_size = 2};
    
    Viewer *viewers[] = { &viewer };
    printf("%d", count_views(viewers, 1, "Soccer")); /* should print 1 */
}
#endif