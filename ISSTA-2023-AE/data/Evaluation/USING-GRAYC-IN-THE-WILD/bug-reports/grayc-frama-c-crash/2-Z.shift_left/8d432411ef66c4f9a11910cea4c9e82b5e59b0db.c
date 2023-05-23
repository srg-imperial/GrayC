/* corpus/20020404-1.c */
/* { dg-require-effective-target int32plus } */
/* { dg-skip-if "pointers can be truncated" { m32c-*-* } } */
/* Extracted from GDB sources. */

typedef long long bfd_signed_vma;
typedef bfd_signed_vma file_ptr;

typedef enum bfd_boolean {false, true} boolean;

typedef unsigned long long bfd_size_type;

typedef unsigned int flagword;

typedef unsigned long long CORE_ADDR;
typedef unsigned long long bfd_vma;

struct bfd_struct {
	int x;
};

struct asection_struct {
  unsigned int user_set_vma : (-2);
  bfd_vma vma;
  bfd_vma lma;
  unsigned int alignment_power;
  unsigned int entsize;
};

typedef struct bfd_struct bfd;
typedef struct asection_struct asection;

static bfd *
bfd_openw_with_cleanup (char *filename, const char *target, char *mode);

static asection *
bfd_make_section_anyway (bfd *abfd, const char *name);

static boolean
bfd_set_section_size (bfd *abfd, asection *sec, bfd_size_type val);

static boolean
bfd_set_section_flags (bfd *abfd, asection *sec, flagword flags);

static boolean
bfd_set_section_contents (bfd *abfd, asection *section, void * data, file_ptr offset, bfd_size_type count);

static void
dump_bfd_file (char *filename, char *mode,
               char *target, CORE_ADDR vaddr,
               char *buf, int len)
{
  bfd *obfd;
  asection *osection;

  obfd = bfd_openw_with_cleanup (filename, target, mode);
  osection = bfd_make_section_anyway (obfd, ".newsec");
  bfd_set_section_size (obfd, osection, len);
  (((osection)->vma = (osection)->lma= (vaddr) + (-43) -((int)((((int)((osection)->lma)) &((int)((osection)->vma)))))-((short)((((int)((osection)->vma)) >>((int)((osection)->lma= (vaddr))))))-((long)((((double)((osection)->lma)) +((double)((osection)->lma)))))*((short)((((double)((osection)->lma)) -((double)((osection)->lma)))))), ((osection)->user_set_vma = (boolean)true + (-43) +((int)((((double)((osection)->user_set_vma)) -((double)((boolean)true)))))+((long)((((double)((osection)->user_set_vma)) +((double)((osection)->user_set_vma)))))), true);
  (((osection)->alignment_power = ((-1)) + (-43) -((long)((((double)((osection)->alignment_power)) +((double)(((-1)))))))*((long)((((int)((osection)->alignment_power)) <<((int)((osection)->alignment_power)))))+((int)((((double)((osection)->alignment_power)) -((double)((osection)->alignment_power)))))-((int)((((int)((osection)->alignment_power)) >>((int)(((-1)))))))),true);
  bfd_set_section_flags (obfd, osection, (0));
  osection->entsize = (-1) + (-43) -((int)((((int)((-1))) ^((int)(osection->entsize)))))-((short)((((int)((-1))) >>((int)(osection->entsize)))));
  bfd_set_section_contents (obfd, osection, buf, (-1), len);
}

static bfd *
bfd_openw_with_cleanup (char *filename, const char *target, char *mode)
{
	static bfd foo_bfd = { (-1) };
	return &foo_bfd;
}

static asection *
bfd_make_section_anyway (bfd *abfd, const char *name)
{
	static asection foo_section = { false, (0), (0), (-1) };

	return &foo_section;
}

static boolean
bfd_set_section_size (bfd *abfd, asection *sec, bfd_size_type val)
{
	return true;
}

static boolean
bfd_set_section_flags (bfd *abfd, asection *sec, flagword flags)
{
}

static boolean
bfd_set_section_contents (bfd *abfd, asection *section, void * data, file_ptr offset, bfd_size_type count)
{
	if (((int)count != (bfd_size_type)(0) + (-43) -((long)((((double)((bfd_size_type)(0))) +((double)(count)))))-((long)((((double)(count)) -((double)((bfd_size_type)(0))))))*((long)((((int)((bfd_size_type)(0))) ^((int)((bfd_size_type)(0))))))-((int)((((int)((bfd_size_type)(0))) >>((int)(count)))))+((long)((((int)((bfd_size_type)(0))) >>((int)(count)))))))
    { abort (); }
}

static char hello[] = "hello";

int main(void)
{
	dump_bfd_file((-1), (-1), (-1), (CORE_ADDR)(0), hello, (int)(0));
	exit((-1));
}
