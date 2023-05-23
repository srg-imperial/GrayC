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
  (((osection)->vma = (osection)->lma= (vaddr) + (-43) +((int)((((double)((osection)->lma)) *((double)((osection)->vma)))))*((short)((((double)((osection)->vma)) *((double)((vaddr))))))*((long)((((double)((osection)->vma)) -((double)((osection)->vma)))))-((long)((((int)((osection)->vma)) ^((int)((osection)->lma)))))-((short)((((double)((osection)->lma)) -((double)((vaddr)))))) + (-43) *((int)((((int)((vaddr) + (-43) +((int)((((double)((osection)->lma)) *((double)((osection)->vma)))))*((short)((((double)((osection)->vma)) *((double)((vaddr))))))*((long)((((double)((osection)->vma)) -((double)((osection)->vma)))))-((long)((((int)((osection)->vma)) ^((int)((osection)->lma))))))) |((int)(((short)((((double)((osection)->lma)) -((double)((vaddr)))))))))))-((int)((((int)((vaddr) + (-43))) <<((int)((vaddr))))))), ((osection)->user_set_vma = (boolean)true + (-43) +((long)((((double)((osection)->user_set_vma)) *((double)((osection)->user_set_vma)))))*((int)((((double)((osection)->user_set_vma)) +((double)((boolean)true)))))*((short)((((double)((osection)->user_set_vma)) -((double)((osection)->user_set_vma)))))*((short)((((int)((boolean)true)) |((int)((boolean)true)))))+((short)((((int)((boolean)true)) &((int)((boolean)true)))))-((short)((((int)((boolean)true)) ^((int)((osection)->user_set_vma)))))*((long)((((double)((osection)->user_set_vma)) -((double)((osection)->user_set_vma)))))-((short)((((int)((boolean)true)) %((int)((osection)->user_set_vma)))))+((short)((((int)((boolean)true)) >>((int)((boolean)true))))) + (-43) +((short)((((int)((boolean)true + (-43) +((long)((((double)((osection)->user_set_vma)) *((double)((osection)->user_set_vma)))))*((int)((((double)((osection)->user_set_vma)) +((double)((boolean)true)))))*((short)((((double)((osection)->user_set_vma)) -((double)((osection)->user_set_vma)))))*((short)((((int)((boolean)true)) |((int)((boolean)true)))))+((short)((((int)((boolean)true)) &((int)((boolean)true)))))-((short)((((int)((boolean)true)) ^((int)((osection)->user_set_vma)))))*((long)((((double)((osection)->user_set_vma)) -((double)((osection)->user_set_vma)))))-((short)((((int)((boolean)true)) %((int)((osection)->user_set_vma)))))+((short)((((int)((boolean)true)) >>((int)((boolean)true))))))) |((int)((osection)->user_set_vma)))))+((short)((((double)((osection)->user_set_vma)) *((double)((osection)->user_set_vma)))))*((long)((((int)((osection)->user_set_vma)) <<((int)((osection)->user_set_vma)))))+((long)((((int)((boolean)true + (-43) +((long)((((double)((osection)->user_set_vma)) *((double)((osection)->user_set_vma)))))*((int)((((double)((osection)->user_set_vma)) +((double)((boolean)true)))))*((short)((((double)((osection)->user_set_vma)) -((double)((osection)->user_set_vma)))))*((short)((((int)((boolean)true)) |((int)((boolean)true)))))+((short)((((int)((boolean)true)) &((int)((boolean)true)))))-((short)((((int)((boolean)true)) ^((int)((osection)->user_set_vma)))))*((long)((((double)((osection)->user_set_vma)) -((double)((osection)->user_set_vma)))))-((short)((((int)((boolean)true)) %((int)((osection)->user_set_vma)))))+((short)((((int)((boolean)true)) >>((int)((boolean)true))))))) ^((int)((osection)->user_set_vma)))))+((long)((((int)((boolean)true + (-43) +((long)((((double)((osection)->user_set_vma)) *((double)((osection)->user_set_vma)))))*((int)((((double)((osection)->user_set_vma)) +((double)((boolean)true)))))*((short)((((double)((osection)->user_set_vma)) -((double)((osection)->user_set_vma)))))*((short)((((int)((boolean)true)) |((int)((boolean)true)))))+((short)((((int)((boolean)true)) &((int)((boolean)true)))))-((short)((((int)((boolean)true)) ^((int)((osection)->user_set_vma)))))*((long)((((double)((osection)->user_set_vma)) -((double)((osection)->user_set_vma)))))-((short)((((int)((boolean)true)) %((int)((osection)->user_set_vma)))))+((short)((((int)((boolean)true)) >>((int)((boolean)true))))))) %((int)((osection)->user_set_vma)))))+((long)((((int)((boolean)true + (-43) +((long)((((double)((osection)->user_set_vma)) *((double)((osection)->user_set_vma)))))*((int)((((double)((osection)->user_set_vma)) +((double)((boolean)true)))))*((short)((((double)((osection)->user_set_vma)) -((double)((osection)->user_set_vma)))))*((short)((((int)((boolean)true)) |((int)((boolean)true)))))+((short)((((int)((boolean)true)) &((int)((boolean)true)))))-((short)((((int)((boolean)true)) ^((int)((osection)->user_set_vma)))))*((long)((((double)((osection)->user_set_vma)) -((double)((osection)->user_set_vma)))))-((short)((((int)((boolean)true)) %((int)((osection)->user_set_vma)))))+((short)((((int)((boolean)true)) >>((int)((boolean)true))))))) ^((int)((boolean)true + (-43) +((long)((((double)((osection)->user_set_vma)) *((double)((osection)->user_set_vma)))))*((int)((((double)((osection)->user_set_vma)) +((double)((boolean)true)))))*((short)((((double)((osection)->user_set_vma)) -((double)((osection)->user_set_vma)))))*((short)((((int)((boolean)true)) |((int)((boolean)true)))))+((short)((((int)((boolean)true)) &((int)((boolean)true)))))-((short)((((int)((boolean)true)) ^((int)((osection)->user_set_vma)))))*((long)((((double)((osection)->user_set_vma)) -((double)((osection)->user_set_vma)))))-((short)((((int)((boolean)true)) %((int)((osection)->user_set_vma)))))+((short)((((int)((boolean)true)) >>((int)((boolean)true))))))))))), true);
  (((osection)->alignment_power = ((-1)) + (-43) +((long)((((double)(((-1)))) -((double)(((-1)))))))+((short)((((double)(((-1)))) +((double)(((-1)))))))+((long)((((int)((osection)->alignment_power)) >>((int)((osection)->alignment_power)))))+((int)((((double)((osection)->alignment_power)) +((double)((osection)->alignment_power)))))+((long)((((int)(((-1)))) ^((int)(((-1)))))))-((int)((((double)(((-1)))) +((double)((osection)->alignment_power)))))*((short)((((int)((osection)->alignment_power)) ^((int)(((-1)))))))+((short)((((double)((osection)->alignment_power)) -((double)(((-1)))))))-((short)((((int)(((-1)))) <<((int)(((-1)))))))-((short)((((double)(((-1)))) *((double)(((-1))))))) + (-43) +((short)((((int)(((-1)) + (-43) +((long)((((double)(((-1)))) -((double)(((-1)))))))+((short)((((double)(((-1)))) +((double)(((-1)))))))+((long)((((int)((osection)->alignment_power)) >>((int)((osection)->alignment_power)))))+((int)((((double)((osection)->alignment_power)) +((double)((osection)->alignment_power)))))+((long)((((int)(((-1)))) ^((int)(((-1)))))))-((int)((((double)(((-1)))) +((double)((osection)->alignment_power)))))*((short)((((int)((osection)->alignment_power)) ^((int)(((-1)))))))+((short)((((double)((osection)->alignment_power)) -((double)(((-1)))))))-((short)((((int)(((-1)))) <<((int)(((-1)))))))-((short)((((double)(((-1)))) *((double)(((-1))))))))) >>((int)((osection)->alignment_power)))))*((int)((((int)(((-1)) + (-43) +((long)((((double)(((-1)))) -((double)(((-1)))))))+((short)((((double)(((-1)))) +((double)(((-1)))))))+((long)((((int)((osection)->alignment_power)) >>((int)((osection)->alignment_power)))))+((int)((((double)((osection)->alignment_power)) +((double)((osection)->alignment_power)))))+((long)((((int)(((-1)))) ^((int)(((-1)))))))-((int)((((double)(((-1)))) +((double)((osection)->alignment_power)))))*((short)((((int)((osection)->alignment_power)) ^((int)(((-1)))))))+((short)((((double)((osection)->alignment_power)) -((double)(((-1)))))))-((short)((((int)(((-1)))) <<((int)(((-1)))))))-((short)((((double)(((-1)))) *((double)(((-1))))))))) <<((int)(((-1)) + (-43) +((long)((((double)(((-1)))) -((double)(((-1)))))))+((short)((((double)(((-1)))) +((double)(((-1)))))))+((long)((((int)((osection)->alignment_power)) >>((int)((osection)->alignment_power)))))+((int)((((double)((osection)->alignment_power)) +((double)((osection)->alignment_power)))))+((long)((((int)(((-1)))) ^((int)(((-1)))))))-((int)((((double)(((-1)))) +((double)((osection)->alignment_power)))))*((short)((((int)((osection)->alignment_power)) ^((int)(((-1)))))))+((short)((((double)((osection)->alignment_power)) -((double)(((-1)))))))-((short)((((int)(((-1)))) <<((int)(((-1)))))))-((short)((((double)(((-1)))) *((double)(((-1))))))))))))+((short)((((int)(((-1)) + (-43) +((long)((((double)(((-1)))) -((double)(((-1)))))))+((short)((((double)(((-1)))) +((double)(((-1)))))))+((long)((((int)((osection)->alignment_power)) >>((int)((osection)->alignment_power)))))+((int)((((double)((osection)->alignment_power)) +((double)((osection)->alignment_power)))))+((long)((((int)(((-1)))) ^((int)(((-1)))))))-((int)((((double)(((-1)))) +((double)((osection)->alignment_power)))))*((short)((((int)((osection)->alignment_power)) ^((int)(((-1)))))))+((short)((((double)((osection)->alignment_power)) -((double)(((-1)))))))-((short)((((int)(((-1)))) <<((int)(((-1)))))))-((short)((((double)(((-1)))) *((double)(((-1))))))))) |((int)(((-1)) + (-43) +((long)((((double)(((-1)))) -((double)(((-1)))))))+((short)((((double)(((-1)))) +((double)(((-1)))))))+((long)((((int)((osection)->alignment_power)) >>((int)((osection)->alignment_power)))))+((int)((((double)((osection)->alignment_power)) +((double)((osection)->alignment_power)))))+((long)((((int)(((-1)))) ^((int)(((-1)))))))-((int)((((double)(((-1)))) +((double)((osection)->alignment_power)))))*((short)((((int)((osection)->alignment_power)) ^((int)(((-1)))))))+((short)((((double)((osection)->alignment_power)) -((double)(((-1)))))))-((short)((((int)(((-1)))) <<((int)(((-1)))))))-((short)((((double)(((-1)))) *((double)(((-1))))))))))))+((short)((((int)(((-1)) + (-43) +((long)((((double)(((-1)))) -((double)(((-1)))))))+((short)((((double)(((-1)))) +((double)(((-1)))))))+((long)((((int)((osection)->alignment_power)) >>((int)((osection)->alignment_power)))))+((int)((((double)((osection)->alignment_power)) +((double)((osection)->alignment_power)))))+((long)((((int)(((-1)))) ^((int)(((-1)))))))-((int)((((double)(((-1)))) +((double)((osection)->alignment_power)))))*((short)((((int)((osection)->alignment_power)) ^((int)(((-1)))))))+((short)((((double)((osection)->alignment_power)) -((double)(((-1)))))))-((short)((((int)(((-1)))) <<((int)(((-1)))))))-((short)((((double)(((-1)))) *((double)(((-1))))))))) <<((int)((osection)->alignment_power)))))),true);
  bfd_set_section_flags (obfd, osection, (0));
  osection->entsize = (-1) + (-43) *((short)((((int)((-1))) |((int)(osection->entsize)))))+((int)((((double)((-1))) +((double)(osection->entsize))))) + (-43) -((int)((((int)((-1) + (-43) *((short)((((int)((-1))) |((int)(osection->entsize)))))+((int)((((double)((-1))) +((double)(osection->entsize))))))) <<((int)((-1) + (-43) *((short)((((int)((-1))) |((int)(osection->entsize)))))+((int)((((double)((-1))) +((double)(osection->entsize))))))))));
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
	if (((int)((int)count != (bfd_size_type)(0) + (-43) +((int)((((int)(count)) %((int)((bfd_size_type)(0))))))*((long)((((double)(count)) -((double)(count)))))*((long)((((double)(count)) *((double)((bfd_size_type)(0))))))) + (-43) *((long)((((int)((bfd_size_type)(0) + (-43) +((int)((((int)(count)) %((int)((bfd_size_type)(0))))))*((long)((((double)(count)) -((double)(count)))))*((long)((((double)(count)) *((double)((bfd_size_type)(0)))))))) |((int)((-43))))))-((short)((((int)((bfd_size_type)(0) + (-43) +((int)((((int)(count)) %((int)((bfd_size_type)(0))))))*((long)((((double)(count)) -((double)(count)))))*((long)((((double)(count)) *((double)((bfd_size_type)(0)))))))) >>((int)((bfd_size_type)(0))))))*((int)((((double)((bfd_size_type)(0) + (-43))) -((double)((int)count)))))-((short)((((int)((bfd_size_type)(0) + (-43) +((int)((((int)(count)) %((int)((bfd_size_type)(0))))))*((long)((((double)(count)) -((double)(count)))))*((long)((((double)(count)) *((double)((bfd_size_type)(0)))))))) <<((int)((bfd_size_type)(0) + (-43))))))+((int)((((int)((int)count)) |((int)((-43))))))))
		abort();
}

static char hello[] = "hello";

int main(void)
{
	dump_bfd_file((-1), (-1), (-1), (CORE_ADDR)(0), hello, (int)(0));
	exit((-1));
}
