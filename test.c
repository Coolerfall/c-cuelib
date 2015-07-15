
#include <stdio.h>
#include "cue_parser.h"

int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		return 0;
	}

	CueSheet *cue_sheet = parse_cue(argv[1]);
	int total_track = cue_sheet->total_track;
	int i;

	for (i = 0; i < total_track; i ++)
	{
		printf("track%d\nalbum: %s\nperformer: %s\ngenre: %s\ntitle: %s\ndate :%s\n"
			"filename: %s\nstart: %d\nend: %d\n", 
			get_int_metadata(cue_sheet, i, TRACK_NUM),
			get_string_metadata(cue_sheet, i, ALBUM_TITLE), 
			get_string_metadata(cue_sheet, i, TRACK_PERFORMER),
			get_string_metadata(cue_sheet, i, GENRE),
			get_string_metadata(cue_sheet, i, TRACK_TITLE),
			get_string_metadata(cue_sheet, i, TRACK_DATE),
			get_string_metadata(cue_sheet, i, FILENAME),
			get_int_metadata(cue_sheet, i, TRACK_START),
			get_int_metadata(cue_sheet, i, TRACK_END));
	}

	char *src = "thisisoriginral";
	printf("index: %d\n", last_index_of(src, "ri"));

	return 0;
}