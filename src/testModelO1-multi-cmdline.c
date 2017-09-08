/*
  File autogenerated by gengetopt version 2.22.6
  generated with the following command:
  gengetopt --file-name=testModelO1-multi-cmdline -C

  The developers of gengetopt consider the fixed text that goes in all
  gengetopt output files to be in the public domain:
  we make no copyright claims on it.
*/

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef FIX_UNUSED
#define FIX_UNUSED(X) (void) (X) /* avoid warnings for unused params */
#endif

#include <getopt.h>

#include "testModelO1-multi-cmdline.h"

const char *gengetopt_args_info_purpose = "";

const char *gengetopt_args_info_usage = "Usage: testModelO1-multi [OPTIONS]...";

const char *gengetopt_args_info_versiontext = "";

const char *gengetopt_args_info_description = "Run a multiple stellar models at O(a^1)";

const char *gengetopt_args_info_help[] = {
  "      --help              Print help and exit",
  "  -V, --version           Print version and exit",
  "\nConfiguration file:",
  "  -C, --conf-file=STRING  Configuration file to read\n                            (default=`modelO1-multi.conf')",
  "\nModel parameter space:",
  "  -l, --pc-low=DOUBLE     Smallest central pressure [dyne/cm^2]\n                            (default=`4.e+34')",
  "  -h, --pc-high=DOUBLE    Largest  central pressure [dyne/cm^2]\n                            (default=`2.e+36')",
  "  -n, --num=INT           Number of models to run (>=2, pressure is log-spaced)\n                            (default=`32')",
  "\nEquation of state:",
  "\n Mode: param-fit\n  Parametrized EoS fit to a numerical model (default).",
  "      --eos-name=STRING   Name of the EoS model.  (possible values=\"PAL6\",\n                            \"SLy\", \"AP1\", \"AP2\", \"AP3\", \"AP4\",\n                            \"FPS\", \"WFF1\", \"WFF2\", \"WFF3\", \"BBB2\",\n                            \"BPAL12\", \"ENG\", \"MPA1\", \"MS1\", \"MS2\",\n                            \"MS1b\", \"PS\", \"GS1\", \"GS2\", \"BGN1H1\",\n                            \"GNH3\", \"H1\", \"H2\", \"H3\", \"H4\", \"H5\",\n                            \"H6\", \"H7\", \"PCL2\", \"ALF1\", \"ALF2\",\n                            \"ALF3\", \"ALF4\" default=`SLy')",
  "\n Mode: param-manual\n  Parametrized EoS with manual parameters.",
  "  -p, --log10p1=DOUBLE    The log (base 10) of (p1 in dyne/cm^2).\n                            (default=`34.384')",
  "  -1, --Gamma1=DOUBLE     Power law index Gamma1  (default=`3.005')",
  "  -2, --Gamma2=DOUBLE     Power law index Gamma2  (default=`2.988')",
  "  -3, --Gamma3=DOUBLE     Power law index Gamma3  (default=`2.851')",
  "\nFile output:",
  "  -o, --out=STRING        The file name to output the multiple model summary\n                            (default=`summary1.dat')",
    0
};

typedef enum {ARG_NO
  , ARG_STRING
  , ARG_INT
  , ARG_DOUBLE
} cmdline_parser_arg_type;

static
void clear_given (struct gengetopt_args_info *args_info);
static
void clear_args (struct gengetopt_args_info *args_info);

static int
cmdline_parser_internal (int argc, char **argv, struct gengetopt_args_info *args_info,
                        struct cmdline_parser_params *params, const char *additional_error);

static int
cmdline_parser_required2 (struct gengetopt_args_info *args_info, const char *prog_name, const char *additional_error);
struct line_list
{
  char * string_arg;
  struct line_list * next;
};

static struct line_list *cmd_line_list = 0;
static struct line_list *cmd_line_list_tmp = 0;

static void
free_cmd_list(void)
{
  /* free the list of a previous call */
  if (cmd_line_list)
    {
      while (cmd_line_list) {
        cmd_line_list_tmp = cmd_line_list;
        cmd_line_list = cmd_line_list->next;
        free (cmd_line_list_tmp->string_arg);
        free (cmd_line_list_tmp);
      }
    }
}


const char *cmdline_parser_eos_name_values[] = {"PAL6", "SLy", "AP1", "AP2", "AP3", "AP4", "FPS", "WFF1", "WFF2", "WFF3", "BBB2", "BPAL12", "ENG", "MPA1", "MS1", "MS2", "MS1b", "PS", "GS1", "GS2", "BGN1H1", "GNH3", "H1", "H2", "H3", "H4", "H5", "H6", "H7", "PCL2", "ALF1", "ALF2", "ALF3", "ALF4", 0}; /*< Possible values for eos-name. */

static char *
gengetopt_strdup (const char *s);

static
void clear_given (struct gengetopt_args_info *args_info)
{
  args_info->help_given = 0 ;
  args_info->version_given = 0 ;
  args_info->conf_file_given = 0 ;
  args_info->pc_low_given = 0 ;
  args_info->pc_high_given = 0 ;
  args_info->num_given = 0 ;
  args_info->eos_name_given = 0 ;
  args_info->log10p1_given = 0 ;
  args_info->Gamma1_given = 0 ;
  args_info->Gamma2_given = 0 ;
  args_info->Gamma3_given = 0 ;
  args_info->out_given = 0 ;
  args_info->param_fit_mode_counter = 0 ;
  args_info->param_manual_mode_counter = 0 ;
}

static
void clear_args (struct gengetopt_args_info *args_info)
{
  FIX_UNUSED (args_info);
  args_info->conf_file_arg = gengetopt_strdup ("modelO1-multi.conf");
  args_info->conf_file_orig = NULL;
  args_info->pc_low_arg = 4.e+34;
  args_info->pc_low_orig = NULL;
  args_info->pc_high_arg = 2.e+36;
  args_info->pc_high_orig = NULL;
  args_info->num_arg = 32;
  args_info->num_orig = NULL;
  args_info->eos_name_arg = gengetopt_strdup ("SLy");
  args_info->eos_name_orig = NULL;
  args_info->log10p1_arg = 34.384;
  args_info->log10p1_orig = NULL;
  args_info->Gamma1_arg = 3.005;
  args_info->Gamma1_orig = NULL;
  args_info->Gamma2_arg = 2.988;
  args_info->Gamma2_orig = NULL;
  args_info->Gamma3_arg = 2.851;
  args_info->Gamma3_orig = NULL;
  args_info->out_arg = gengetopt_strdup ("summary1.dat");
  args_info->out_orig = NULL;
  
}

static
void init_args_info(struct gengetopt_args_info *args_info)
{


  args_info->help_help = gengetopt_args_info_help[0] ;
  args_info->version_help = gengetopt_args_info_help[1] ;
  args_info->conf_file_help = gengetopt_args_info_help[3] ;
  args_info->pc_low_help = gengetopt_args_info_help[5] ;
  args_info->pc_high_help = gengetopt_args_info_help[6] ;
  args_info->num_help = gengetopt_args_info_help[7] ;
  args_info->eos_name_help = gengetopt_args_info_help[10] ;
  args_info->log10p1_help = gengetopt_args_info_help[12] ;
  args_info->Gamma1_help = gengetopt_args_info_help[13] ;
  args_info->Gamma2_help = gengetopt_args_info_help[14] ;
  args_info->Gamma3_help = gengetopt_args_info_help[15] ;
  args_info->out_help = gengetopt_args_info_help[17] ;
  
}

void
cmdline_parser_print_version (void)
{
  printf ("%s %s\n",
     (strlen(CMDLINE_PARSER_PACKAGE_NAME) ? CMDLINE_PARSER_PACKAGE_NAME : CMDLINE_PARSER_PACKAGE),
     CMDLINE_PARSER_VERSION);

  if (strlen(gengetopt_args_info_versiontext) > 0)
    printf("\n%s\n", gengetopt_args_info_versiontext);
}

static void print_help_common(void) {
  cmdline_parser_print_version ();

  if (strlen(gengetopt_args_info_purpose) > 0)
    printf("\n%s\n", gengetopt_args_info_purpose);

  if (strlen(gengetopt_args_info_usage) > 0)
    printf("\n%s\n", gengetopt_args_info_usage);

  printf("\n");

  if (strlen(gengetopt_args_info_description) > 0)
    printf("%s\n\n", gengetopt_args_info_description);
}

void
cmdline_parser_print_help (void)
{
  int i = 0;
  print_help_common();
  while (gengetopt_args_info_help[i])
    printf("%s\n", gengetopt_args_info_help[i++]);
}

void
cmdline_parser_init (struct gengetopt_args_info *args_info)
{
  clear_given (args_info);
  clear_args (args_info);
  init_args_info (args_info);
}

void
cmdline_parser_params_init(struct cmdline_parser_params *params)
{
  if (params)
    { 
      params->override = 0;
      params->initialize = 1;
      params->check_required = 1;
      params->check_ambiguity = 0;
      params->print_errors = 1;
    }
}

struct cmdline_parser_params *
cmdline_parser_params_create(void)
{
  struct cmdline_parser_params *params = 
    (struct cmdline_parser_params *)malloc(sizeof(struct cmdline_parser_params));
  cmdline_parser_params_init(params);  
  return params;
}

static void
free_string_field (char **s)
{
  if (*s)
    {
      free (*s);
      *s = 0;
    }
}


static void
cmdline_parser_release (struct gengetopt_args_info *args_info)
{

  free_string_field (&(args_info->conf_file_arg));
  free_string_field (&(args_info->conf_file_orig));
  free_string_field (&(args_info->pc_low_orig));
  free_string_field (&(args_info->pc_high_orig));
  free_string_field (&(args_info->num_orig));
  free_string_field (&(args_info->eos_name_arg));
  free_string_field (&(args_info->eos_name_orig));
  free_string_field (&(args_info->log10p1_orig));
  free_string_field (&(args_info->Gamma1_orig));
  free_string_field (&(args_info->Gamma2_orig));
  free_string_field (&(args_info->Gamma3_orig));
  free_string_field (&(args_info->out_arg));
  free_string_field (&(args_info->out_orig));
  
  

  clear_given (args_info);
}

/**
 * @param val the value to check
 * @param values the possible values
 * @return the index of the matched value:
 * -1 if no value matched,
 * -2 if more than one value has matched
 */
static int
check_possible_values(const char *val, const char *values[])
{
  int i, found, last;
  size_t len;

  if (!val)   /* otherwise strlen() crashes below */
    return -1; /* -1 means no argument for the option */

  found = last = 0;

  for (i = 0, len = strlen(val); values[i]; ++i)
    {
      if (strncmp(val, values[i], len) == 0)
        {
          ++found;
          last = i;
          if (strlen(values[i]) == len)
            return i; /* exact macth no need to check more */
        }
    }

  if (found == 1) /* one match: OK */
    return last;

  return (found ? -2 : -1); /* return many values or none matched */
}


static void
write_into_file(FILE *outfile, const char *opt, const char *arg, const char *values[])
{
  int found = -1;
  if (arg) {
    if (values) {
      found = check_possible_values(arg, values);      
    }
    if (found >= 0)
      fprintf(outfile, "%s=\"%s\" # %s\n", opt, arg, values[found]);
    else
      fprintf(outfile, "%s=\"%s\"\n", opt, arg);
  } else {
    fprintf(outfile, "%s\n", opt);
  }
}


int
cmdline_parser_dump(FILE *outfile, struct gengetopt_args_info *args_info)
{
  int i = 0;

  if (!outfile)
    {
      fprintf (stderr, "%s: cannot dump options to stream\n", CMDLINE_PARSER_PACKAGE);
      return EXIT_FAILURE;
    }

  if (args_info->help_given)
    write_into_file(outfile, "help", 0, 0 );
  if (args_info->version_given)
    write_into_file(outfile, "version", 0, 0 );
  if (args_info->conf_file_given)
    write_into_file(outfile, "conf-file", args_info->conf_file_orig, 0);
  if (args_info->pc_low_given)
    write_into_file(outfile, "pc-low", args_info->pc_low_orig, 0);
  if (args_info->pc_high_given)
    write_into_file(outfile, "pc-high", args_info->pc_high_orig, 0);
  if (args_info->num_given)
    write_into_file(outfile, "num", args_info->num_orig, 0);
  if (args_info->eos_name_given)
    write_into_file(outfile, "eos-name", args_info->eos_name_orig, cmdline_parser_eos_name_values);
  if (args_info->log10p1_given)
    write_into_file(outfile, "log10p1", args_info->log10p1_orig, 0);
  if (args_info->Gamma1_given)
    write_into_file(outfile, "Gamma1", args_info->Gamma1_orig, 0);
  if (args_info->Gamma2_given)
    write_into_file(outfile, "Gamma2", args_info->Gamma2_orig, 0);
  if (args_info->Gamma3_given)
    write_into_file(outfile, "Gamma3", args_info->Gamma3_orig, 0);
  if (args_info->out_given)
    write_into_file(outfile, "out", args_info->out_orig, 0);
  

  i = EXIT_SUCCESS;
  return i;
}

int
cmdline_parser_file_save(const char *filename, struct gengetopt_args_info *args_info)
{
  FILE *outfile;
  int i = 0;

  outfile = fopen(filename, "w");

  if (!outfile)
    {
      fprintf (stderr, "%s: cannot open file for writing: %s\n", CMDLINE_PARSER_PACKAGE, filename);
      return EXIT_FAILURE;
    }

  i = cmdline_parser_dump(outfile, args_info);
  fclose (outfile);

  return i;
}

void
cmdline_parser_free (struct gengetopt_args_info *args_info)
{
  cmdline_parser_release (args_info);
}

/** @brief replacement of strdup, which is not standard */
char *
gengetopt_strdup (const char *s)
{
  char *result = 0;
  if (!s)
    return result;

  result = (char*)malloc(strlen(s) + 1);
  if (result == (char*)0)
    return (char*)0;
  strcpy(result, s);
  return result;
}

int
cmdline_parser (int argc, char **argv, struct gengetopt_args_info *args_info)
{
  return cmdline_parser2 (argc, argv, args_info, 0, 1, 1);
}

int
cmdline_parser_ext (int argc, char **argv, struct gengetopt_args_info *args_info,
                   struct cmdline_parser_params *params)
{
  int result;
  result = cmdline_parser_internal (argc, argv, args_info, params, 0);

  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
cmdline_parser2 (int argc, char **argv, struct gengetopt_args_info *args_info, int override, int initialize, int check_required)
{
  int result;
  struct cmdline_parser_params params;
  
  params.override = override;
  params.initialize = initialize;
  params.check_required = check_required;
  params.check_ambiguity = 0;
  params.print_errors = 1;

  result = cmdline_parser_internal (argc, argv, args_info, &params, 0);

  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
cmdline_parser_required (struct gengetopt_args_info *args_info, const char *prog_name)
{
  int result = EXIT_SUCCESS;

  if (cmdline_parser_required2(args_info, prog_name, 0) > 0)
    result = EXIT_FAILURE;

  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
cmdline_parser_required2 (struct gengetopt_args_info *args_info, const char *prog_name, const char *additional_error)
{
  int error_occurred = 0;
  FIX_UNUSED (additional_error);

  /* checks for required options */
  if (! args_info->pc_low_given)
    {
      fprintf (stderr, "%s: '--pc-low' ('-l') option required%s\n", prog_name, (additional_error ? additional_error : ""));
      error_occurred = 1;
    }
  
  if (! args_info->pc_high_given)
    {
      fprintf (stderr, "%s: '--pc-high' ('-h') option required%s\n", prog_name, (additional_error ? additional_error : ""));
      error_occurred = 1;
    }
  
  if (args_info->param_manual_mode_counter && ! args_info->log10p1_given)
    {
      fprintf (stderr, "%s: '--log10p1' ('-p') option required%s\n", prog_name, (additional_error ? additional_error : ""));
      error_occurred = 1;
    }
  
  if (args_info->param_manual_mode_counter && ! args_info->Gamma1_given)
    {
      fprintf (stderr, "%s: '--Gamma1' ('-1') option required%s\n", prog_name, (additional_error ? additional_error : ""));
      error_occurred = 1;
    }
  
  if (args_info->param_manual_mode_counter && ! args_info->Gamma2_given)
    {
      fprintf (stderr, "%s: '--Gamma2' ('-2') option required%s\n", prog_name, (additional_error ? additional_error : ""));
      error_occurred = 1;
    }
  
  if (args_info->param_manual_mode_counter && ! args_info->Gamma3_given)
    {
      fprintf (stderr, "%s: '--Gamma3' ('-3') option required%s\n", prog_name, (additional_error ? additional_error : ""));
      error_occurred = 1;
    }
  
  
  /* checks for dependences among options */

  return error_occurred;
}


static char *package_name = 0;

/**
 * @brief updates an option
 * @param field the generic pointer to the field to update
 * @param orig_field the pointer to the orig field
 * @param field_given the pointer to the number of occurrence of this option
 * @param prev_given the pointer to the number of occurrence already seen
 * @param value the argument for this option (if null no arg was specified)
 * @param possible_values the possible values for this option (if specified)
 * @param default_value the default value (in case the option only accepts fixed values)
 * @param arg_type the type of this option
 * @param check_ambiguity @see cmdline_parser_params.check_ambiguity
 * @param override @see cmdline_parser_params.override
 * @param no_free whether to free a possible previous value
 * @param multiple_option whether this is a multiple option
 * @param long_opt the corresponding long option
 * @param short_opt the corresponding short option (or '-' if none)
 * @param additional_error possible further error specification
 */
static
int update_arg(void *field, char **orig_field,
               unsigned int *field_given, unsigned int *prev_given, 
               char *value, const char *possible_values[],
               const char *default_value,
               cmdline_parser_arg_type arg_type,
               int check_ambiguity, int override,
               int no_free, int multiple_option,
               const char *long_opt, char short_opt,
               const char *additional_error)
{
  char *stop_char = 0;
  const char *val = value;
  int found;
  char **string_field;
  FIX_UNUSED (field);

  stop_char = 0;
  found = 0;

  if (!multiple_option && prev_given && (*prev_given || (check_ambiguity && *field_given)))
    {
      if (short_opt != '-')
        fprintf (stderr, "%s: `--%s' (`-%c') option given more than once%s\n", 
               package_name, long_opt, short_opt,
               (additional_error ? additional_error : ""));
      else
        fprintf (stderr, "%s: `--%s' option given more than once%s\n", 
               package_name, long_opt,
               (additional_error ? additional_error : ""));
      return 1; /* failure */
    }

  if (possible_values && (found = check_possible_values((value ? value : default_value), possible_values)) < 0)
    {
      if (short_opt != '-')
        fprintf (stderr, "%s: %s argument, \"%s\", for option `--%s' (`-%c')%s\n", 
          package_name, (found == -2) ? "ambiguous" : "invalid", value, long_opt, short_opt,
          (additional_error ? additional_error : ""));
      else
        fprintf (stderr, "%s: %s argument, \"%s\", for option `--%s'%s\n", 
          package_name, (found == -2) ? "ambiguous" : "invalid", value, long_opt,
          (additional_error ? additional_error : ""));
      return 1; /* failure */
    }
    
  if (field_given && *field_given && ! override)
    return 0;
  if (prev_given)
    (*prev_given)++;
  if (field_given)
    (*field_given)++;
  if (possible_values)
    val = possible_values[found];

  switch(arg_type) {
  case ARG_INT:
    if (val) *((int *)field) = strtol (val, &stop_char, 0);
    break;
  case ARG_DOUBLE:
    if (val) *((double *)field) = strtod (val, &stop_char);
    break;
  case ARG_STRING:
    if (val) {
      string_field = (char **)field;
      if (!no_free && *string_field)
        free (*string_field); /* free previous string */
      *string_field = gengetopt_strdup (val);
    }
    break;
  default:
    break;
  };

  /* check numeric conversion */
  switch(arg_type) {
  case ARG_INT:
  case ARG_DOUBLE:
    if (val && !(stop_char && *stop_char == '\0')) {
      fprintf(stderr, "%s: invalid numeric value: %s\n", package_name, val);
      return 1; /* failure */
    }
    break;
  default:
    ;
  };

  /* store the original value */
  switch(arg_type) {
  case ARG_NO:
    break;
  default:
    if (value && orig_field) {
      if (no_free) {
        *orig_field = value;
      } else {
        if (*orig_field)
          free (*orig_field); /* free previous string */
        *orig_field = gengetopt_strdup (value);
      }
    }
  };

  return 0; /* OK */
}


static int check_modes(
  int given1[], const char *options1[],
                       int given2[], const char *options2[])
{
  int i = 0, j = 0, errors = 0;
  
  while (given1[i] >= 0) {
    if (given1[i]) {
      while (given2[j] >= 0) {
        if (given2[j]) {
          ++errors;
          fprintf(stderr, "%s: option %s conflicts with option %s\n",
                  package_name, options1[i], options2[j]);
        }
        ++j;
      }
    }
    ++i;
  }
  
  return errors;
}

int
cmdline_parser_internal (
  int argc, char **argv, struct gengetopt_args_info *args_info,
                        struct cmdline_parser_params *params, const char *additional_error)
{
  int c;	/* Character of the parsed option.  */

  int error_occurred = 0;
  struct gengetopt_args_info local_args_info;
  
  int override;
  int initialize;
  int check_required;
  int check_ambiguity;
  
  package_name = argv[0];
  
  override = params->override;
  initialize = params->initialize;
  check_required = params->check_required;
  check_ambiguity = params->check_ambiguity;

  if (initialize)
    cmdline_parser_init (args_info);

  cmdline_parser_init (&local_args_info);

  optarg = 0;
  optind = 0;
  opterr = params->print_errors;
  optopt = '?';

  while (1)
    {
      int option_index = 0;

      static struct option long_options[] = {
        { "help",	0, NULL, 0 },
        { "version",	0, NULL, 'V' },
        { "conf-file",	1, NULL, 'C' },
        { "pc-low",	1, NULL, 'l' },
        { "pc-high",	1, NULL, 'h' },
        { "num",	1, NULL, 'n' },
        { "eos-name",	1, NULL, 0 },
        { "log10p1",	1, NULL, 'p' },
        { "Gamma1",	1, NULL, '1' },
        { "Gamma2",	1, NULL, '2' },
        { "Gamma3",	1, NULL, '3' },
        { "out",	1, NULL, 'o' },
        { 0,  0, 0, 0 }
      };

      c = getopt_long (argc, argv, "VC:l:h:n:p:1:2:3:o:", long_options, &option_index);

      if (c == -1) break;	/* Exit from `while (1)' loop.  */

      switch (c)
        {
        case 'V':	/* Print version and exit.  */
          cmdline_parser_print_version ();
          cmdline_parser_free (&local_args_info);
          exit (EXIT_SUCCESS);

        case 'C':	/* Configuration file to read.  */
        
        
          if (update_arg( (void *)&(args_info->conf_file_arg), 
               &(args_info->conf_file_orig), &(args_info->conf_file_given),
              &(local_args_info.conf_file_given), optarg, 0, "modelO1-multi.conf", ARG_STRING,
              check_ambiguity, override, 0, 0,
              "conf-file", 'C',
              additional_error))
            goto failure;
        
          break;
        case 'l':	/* Smallest central pressure [dyne/cm^2].  */
        
        
          if (update_arg( (void *)&(args_info->pc_low_arg), 
               &(args_info->pc_low_orig), &(args_info->pc_low_given),
              &(local_args_info.pc_low_given), optarg, 0, "4.e+34", ARG_DOUBLE,
              check_ambiguity, override, 0, 0,
              "pc-low", 'l',
              additional_error))
            goto failure;
        
          break;
        case 'h':	/* Largest  central pressure [dyne/cm^2].  */
        
        
          if (update_arg( (void *)&(args_info->pc_high_arg), 
               &(args_info->pc_high_orig), &(args_info->pc_high_given),
              &(local_args_info.pc_high_given), optarg, 0, "2.e+36", ARG_DOUBLE,
              check_ambiguity, override, 0, 0,
              "pc-high", 'h',
              additional_error))
            goto failure;
        
          break;
        case 'n':	/* Number of models to run (>=2, pressure is log-spaced).  */
        
        
          if (update_arg( (void *)&(args_info->num_arg), 
               &(args_info->num_orig), &(args_info->num_given),
              &(local_args_info.num_given), optarg, 0, "32", ARG_INT,
              check_ambiguity, override, 0, 0,
              "num", 'n',
              additional_error))
            goto failure;
        
          break;
        case 'p':	/* The log (base 10) of (p1 in dyne/cm^2)..  */
          args_info->param_manual_mode_counter += 1;
        
        
          if (update_arg( (void *)&(args_info->log10p1_arg), 
               &(args_info->log10p1_orig), &(args_info->log10p1_given),
              &(local_args_info.log10p1_given), optarg, 0, "34.384", ARG_DOUBLE,
              check_ambiguity, override, 0, 0,
              "log10p1", 'p',
              additional_error))
            goto failure;
        
          break;
        case '1':	/* Power law index Gamma1.  */
          args_info->param_manual_mode_counter += 1;
        
        
          if (update_arg( (void *)&(args_info->Gamma1_arg), 
               &(args_info->Gamma1_orig), &(args_info->Gamma1_given),
              &(local_args_info.Gamma1_given), optarg, 0, "3.005", ARG_DOUBLE,
              check_ambiguity, override, 0, 0,
              "Gamma1", '1',
              additional_error))
            goto failure;
        
          break;
        case '2':	/* Power law index Gamma2.  */
          args_info->param_manual_mode_counter += 1;
        
        
          if (update_arg( (void *)&(args_info->Gamma2_arg), 
               &(args_info->Gamma2_orig), &(args_info->Gamma2_given),
              &(local_args_info.Gamma2_given), optarg, 0, "2.988", ARG_DOUBLE,
              check_ambiguity, override, 0, 0,
              "Gamma2", '2',
              additional_error))
            goto failure;
        
          break;
        case '3':	/* Power law index Gamma3.  */
          args_info->param_manual_mode_counter += 1;
        
        
          if (update_arg( (void *)&(args_info->Gamma3_arg), 
               &(args_info->Gamma3_orig), &(args_info->Gamma3_given),
              &(local_args_info.Gamma3_given), optarg, 0, "2.851", ARG_DOUBLE,
              check_ambiguity, override, 0, 0,
              "Gamma3", '3',
              additional_error))
            goto failure;
        
          break;
        case 'o':	/* The file name to output the multiple model summary.  */
        
        
          if (update_arg( (void *)&(args_info->out_arg), 
               &(args_info->out_orig), &(args_info->out_given),
              &(local_args_info.out_given), optarg, 0, "summary1.dat", ARG_STRING,
              check_ambiguity, override, 0, 0,
              "out", 'o',
              additional_error))
            goto failure;
        
          break;

        case 0:	/* Long option with no short option */
          if (strcmp (long_options[option_index].name, "help") == 0) {
            cmdline_parser_print_help ();
            cmdline_parser_free (&local_args_info);
            exit (EXIT_SUCCESS);
          }

          /* Name of the EoS model..  */
          if (strcmp (long_options[option_index].name, "eos-name") == 0)
          {
            args_info->param_fit_mode_counter += 1;
          
          
            if (update_arg( (void *)&(args_info->eos_name_arg), 
                 &(args_info->eos_name_orig), &(args_info->eos_name_given),
                &(local_args_info.eos_name_given), optarg, cmdline_parser_eos_name_values, "SLy", ARG_STRING,
                check_ambiguity, override, 0, 0,
                "eos-name", '-',
                additional_error))
              goto failure;
          
          }
          
          break;
        case '?':	/* Invalid option.  */
          /* `getopt_long' already printed an error message.  */
          goto failure;

        default:	/* bug: option not considered.  */
          fprintf (stderr, "%s: option unknown: %c%s\n", CMDLINE_PARSER_PACKAGE, c, (additional_error ? additional_error : ""));
          abort ();
        } /* switch */
    } /* while */



  if (args_info->param_fit_mode_counter && args_info->param_manual_mode_counter) {
    int param_fit_given[] = {args_info->eos_name_given,  -1};
    const char *param_fit_desc[] = {"--eos-name",  0};
    int param_manual_given[] = {args_info->log10p1_given, args_info->Gamma1_given, args_info->Gamma2_given, args_info->Gamma3_given,  -1};
    const char *param_manual_desc[] = {"--log10p1", "--Gamma1", "--Gamma2", "--Gamma3",  0};
    error_occurred += check_modes(param_fit_given, param_fit_desc, param_manual_given, param_manual_desc);
  }
  
  if (check_required)
    {
      error_occurred += cmdline_parser_required2 (args_info, argv[0], additional_error);
    }

  cmdline_parser_release (&local_args_info);

  if ( error_occurred )
    return (EXIT_FAILURE);

  return 0;

failure:
  
  cmdline_parser_release (&local_args_info);
  return (EXIT_FAILURE);
}

#ifndef CONFIG_FILE_LINE_SIZE
#define CONFIG_FILE_LINE_SIZE 2048
#endif
#define ADDITIONAL_ERROR " in configuration file "

#define CONFIG_FILE_LINE_BUFFER_SIZE (CONFIG_FILE_LINE_SIZE+3)
/* 3 is for "--" and "=" */

static int
_cmdline_parser_configfile (const char *filename, int *my_argc)
{
  FILE* file;
  char my_argv[CONFIG_FILE_LINE_BUFFER_SIZE+1];
  char linebuf[CONFIG_FILE_LINE_SIZE];
  int line_num = 0;
  int result = 0, equal;
  char *fopt, *farg;
  char *str_index;
  size_t len, next_token;
  char delimiter;

  if ((file = fopen(filename, "r")) == 0)
    {
      fprintf (stderr, "%s: Error opening configuration file '%s'\n",
               CMDLINE_PARSER_PACKAGE, filename);
      return EXIT_FAILURE;
    }

  while ((fgets(linebuf, CONFIG_FILE_LINE_SIZE, file)) != 0)
    {
      ++line_num;
      my_argv[0] = '\0';
      len = strlen(linebuf);
      if (len > (CONFIG_FILE_LINE_BUFFER_SIZE-1))
        {
          fprintf (stderr, "%s:%s:%d: Line too long in configuration file\n",
                   CMDLINE_PARSER_PACKAGE, filename, line_num);
          result = EXIT_FAILURE;
          break;
        }

      /* find first non-whitespace character in the line */
      next_token = strspn (linebuf, " \t\r\n");
      str_index  = linebuf + next_token;

      if ( str_index[0] == '\0' || str_index[0] == '#')
        continue; /* empty line or comment line is skipped */

      fopt = str_index;

      /* truncate fopt at the end of the first non-valid character */
      next_token = strcspn (fopt, " \t\r\n=");

      if (fopt[next_token] == '\0') /* the line is over */
        {
          farg  = 0;
          equal = 0;
          goto noarg;
        }

      /* remember if equal sign is present */
      equal = (fopt[next_token] == '=');
      fopt[next_token++] = '\0';

      /* advance pointers to the next token after the end of fopt */
      next_token += strspn (fopt + next_token, " \t\r\n");

      /* check for the presence of equal sign, and if so, skip it */
      if ( !equal )
        if ((equal = (fopt[next_token] == '=')))
          {
            next_token++;
            next_token += strspn (fopt + next_token, " \t\r\n");
          }
      str_index  += next_token;

      /* find argument */
      farg = str_index;
      if ( farg[0] == '\"' || farg[0] == '\'' )
        { /* quoted argument */
          str_index = strchr (++farg, str_index[0] ); /* skip opening quote */
          if (! str_index)
            {
              fprintf
                (stderr,
                 "%s:%s:%d: unterminated string in configuration file\n",
                 CMDLINE_PARSER_PACKAGE, filename, line_num);
              result = EXIT_FAILURE;
              break;
            }
        }
      else
        { /* read up the remaining part up to a delimiter */
          next_token = strcspn (farg, " \t\r\n#\'\"");
          str_index += next_token;
        }

      /* truncate farg at the delimiter and store it for further check */
      delimiter = *str_index, *str_index++ = '\0';

      /* everything but comment is illegal at the end of line */
      if (delimiter != '\0' && delimiter != '#')
        {
          str_index += strspn(str_index, " \t\r\n");
          if (*str_index != '\0' && *str_index != '#')
            {
              fprintf
                (stderr,
                 "%s:%s:%d: malformed string in configuration file\n",
                 CMDLINE_PARSER_PACKAGE, filename, line_num);
              result = EXIT_FAILURE;
              break;
            }
        }

    noarg:
      if (!strcmp(fopt,"include")) {
        if (farg && *farg) {
          result = _cmdline_parser_configfile(farg, my_argc);
        } else {
          fprintf(stderr, "%s:%s:%d: include requires a filename argument.\n",
                  CMDLINE_PARSER_PACKAGE, filename, line_num);
        }
        continue;
      }
      len = strlen(fopt);
      strcat (my_argv, len > 1 ? "--" : "-");
      strcat (my_argv, fopt);
      if (len > 1 && ((farg && *farg) || equal))
        strcat (my_argv, "=");
      if (farg && *farg)
        strcat (my_argv, farg);
      ++(*my_argc);

      cmd_line_list_tmp = (struct line_list *) malloc (sizeof (struct line_list));
      cmd_line_list_tmp->next = cmd_line_list;
      cmd_line_list = cmd_line_list_tmp;
      cmd_line_list->string_arg = gengetopt_strdup(my_argv);
    } /* while */

  if (file)
    fclose(file);
  return result;
}

int
cmdline_parser_configfile (
  const char *filename,
                           struct gengetopt_args_info *args_info,
                           int override, int initialize, int check_required)
{
  struct cmdline_parser_params params;

  params.override = override;
  params.initialize = initialize;
  params.check_required = check_required;
  params.check_ambiguity = 0;
  params.print_errors = 1;
  
  return cmdline_parser_config_file (filename, args_info, &params);
}

int
cmdline_parser_config_file (const char *filename,
                           struct gengetopt_args_info *args_info,
                           struct cmdline_parser_params *params)
{
  int i, result;
  int my_argc = 1;
  char **my_argv_arg;
  char *additional_error;

  /* store the program name */
  cmd_line_list_tmp = (struct line_list *) malloc (sizeof (struct line_list));
  cmd_line_list_tmp->next = cmd_line_list;
  cmd_line_list = cmd_line_list_tmp;
  cmd_line_list->string_arg = gengetopt_strdup (CMDLINE_PARSER_PACKAGE);

  result = _cmdline_parser_configfile(filename, &my_argc);

  if (result != EXIT_FAILURE) {
    my_argv_arg = (char **) malloc((my_argc+1) * sizeof(char *));
    cmd_line_list_tmp = cmd_line_list;

    for (i = my_argc - 1; i >= 0; --i) {
      my_argv_arg[i] = cmd_line_list_tmp->string_arg;
      cmd_line_list_tmp = cmd_line_list_tmp->next;
    }

    my_argv_arg[my_argc] = 0;

    additional_error = (char *)malloc(strlen(filename) + strlen(ADDITIONAL_ERROR) + 1);
    strcpy (additional_error, ADDITIONAL_ERROR);
    strcat (additional_error, filename);
    result =
      cmdline_parser_internal (my_argc, my_argv_arg, args_info,
                              params,
                              additional_error);

    free (additional_error);
    free (my_argv_arg);
  }

  free_cmd_list();
  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}
