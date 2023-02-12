## macOS FAT16 Mount Blocker

Small background utility that prevents macOS from writing to FAT16 volumes while the utility is active. There is no configuration. Just launch the app and your FAT16 volumes are protected.

It is forked from https://github.com/aburgh/Disk-Arbitrator with some slight modifications to hide configuration options and enforce the default behaviour we need.

## Download

[Download here](https://github.com/izzyreal/macos-fat16-mount-blocker/releases/download/0.8/FAT16.Mount.Blocker-0.8.dmg).

### Background

The Akai MPC2000XL integrated sequencer/sampler uses a [tweaked version of the FAT16 filesystem](https://vmpcdocs.izmar.nl/vmpc_specific_settings.html#background). The tweak consists of allowing file names of up to 16 characters, as opposed to 8 characters, which is standard for FAT16. This is why MPC2000XL sound names can be 16 characters long.

Now, what happens when you insert your MPC2000XL CF card or other media in a Mac, is that macOS will write new files to it: files for Spotlight and for `fseventsd`. Part of writing new files to a volume includes _rewriting_ what was already there in the file allocation table -- something that macOS does not know how to do in the Akai-tweaked way.

What was means in practice is that your 2KXL CF and other media will be corrupted the moment you put them in a Mac, if they have files with names longer than 8 characters. The `SND` files in question will still be there, but their names have become mangled, so any `PGM` files that depend on these `SND` files having long file names will no longer find its sounds.

By mounting FAT16 volumes as read-only, `FAT16 Mount Blocker` protects your MPC2000XL's CF and other media from this kind of corruption.
