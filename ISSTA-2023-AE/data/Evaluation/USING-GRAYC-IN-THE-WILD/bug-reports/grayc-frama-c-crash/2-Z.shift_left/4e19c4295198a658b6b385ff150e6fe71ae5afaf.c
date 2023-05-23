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
  (((osection)->vma = (osection)->lma= (vaddr) + (-43) +((short)((((double)((osection)->vma)) -((double)((osection)->vma)))))*((long)((((int)((vaddr))) |((int)((vaddr))))))-((long)((((double)((osection)->lma= (vaddr))) +((double)((osection)->lma= (vaddr))))))*((short)((((double)((osection)->lma= (vaddr))) -((double)((vaddr))))))-((long)((((int)((osection)->vma)) <<((int)((vaddr))))))*((short)((((double)((vaddr))) *((double)((osection)->vma)))))+((short)((((double)((osection)->vma)) +((double)((vaddr))))))), ((osection)->user_set_vma = (boolean)true + (-43) -((int)((((int)((boolean)true)) ^((int)((boolean)true)))))*((short)((((int)((osection)->user_set_vma)) ^((int)((boolean)true)))))), true);
  (((osection)->alignment_power = ((-1)) + (-43) -((long)((((int)(((-1)))) <<((int)((osection)->alignment_power)))))-((long)((((double)((osection)->alignment_power)) -((double)((osection)->alignment_power)))))-((short)((((double)(((-1)))) -((double)(((-1)))))))-((short)((((double)(((-1)))) -((double)((osection)->alignment_power)))))+((long)((((int)(((-1)))) ^((int)(((-1)))))))*((short)((((int)(((-1)))) |((int)(((-1)))))))+((int)((((double)(((-1)))) +((double)((osection)->alignment_power)))))+((int)((((double)(((-1)))) *((double)(((-1)))))))-((long)((((int)((osection)->alignment_power)) ^((int)(((-1)))))))),true);
  bfd_set_section_flags (obfd, osection, (0));
  osection->entsize = (-1) + (-43) *((int)((((double)(osection->entsize)) +((double)((-1))))))*((int)((((double)(osection->entsize)) -((double)((-1))))))+((long)((((double)((-1))) +((double)(osection->entsize)))))+((long)((((double)((-1))) -((double)(osection->entsize)))))*((long)((((int)((-1))) >>((int)(osection->entsize)))))+((short)((((double)((-1))) +((double)(osection->entsize)))))-((int)((((int)((-1))) %((int)(osection->entsize)))))+((long)((((int)((-1))) |((int)((-1))))));
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
	if ((-1))
		abort();
}

static char hello[] = "hello";

int main(void)
{
	dump_bfd_file((-1), (-1), (-1), (CORE_ADDR)(0), hello, (int)(0));
	exit((-1));
}
